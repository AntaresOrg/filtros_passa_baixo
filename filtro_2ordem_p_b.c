#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846f

typedef struct {
    float b0, b1, b2;
    float a1, a2;
    float w1, w2;
} DF2T;

void calcular_coef(float fc, float fs, DF2T *p) {
    float norm = fc / fs;
    float omega = 2.0f * PI * norm;
    float cosw = cosf(omega);
    float sinw = sinf(omega);
    float Q = 0.7071f;
    float alpha = sinw / (2.0f * Q);

    float a0 = 1.0f + alpha;
    p->b0 = ((1.0f - cosw) / 2.0f) / a0;
    p->b1 = (1.0f - cosw) / a0;
    p->b2 = ((1.0f - cosw) / 2.0f) / a0;
    p->a1 = (-2.0f * cosw) / a0;
    p->a2 = (1.0f - alpha) / a0;
    
    p->w1 = 0.0f;
    p->w2 = 0.0f;
}

float filtro_processar(DF2T *p, float x) {
    float y = p->b0 * x + p->w1;
    p->w1 = p->b1 * x - p->a1 * y + p->w2;
    p->w2 = p->b2 * x - p->a2 * y;
    return y;
}

int main() {
    float h_lida, p_lida, t_lida;
    float h_filt, p_filt, t_filt;

    DF2T f_h, f_p, f_t;

    calcular_coef(2.0f, 100.0f, &f_h);
    calcular_coef(2.0f, 100.0f, &f_p);
    calcular_coef(2.0f, 100.0f, &f_t);

    FILE *arq_in = fopen("dados.txt", "r");
    if (!arq_in) {
        perror("Erro");
        return 1;
    }

    FILE *arq_out = fopen("output.txt", "w");
    if (!arq_out) {
        perror("Erro");
        fclose(arq_in);
        return 1;
    }

    fprintf(arq_out, "ALTURA_FILTRADA, PRESSAO_FILTRADA, TEMPERATURA_FILTRADA\n");

    while (fscanf(arq_in, "%f %f %f", &h_lida, &p_lida, &t_lida) == 3) {
        h_filt = filtro_processar(&f_h, h_lida);
        p_filt = filtro_processar(&f_p, p_lida);
        t_filt = filtro_processar(&f_t, t_lida);

        fprintf(arq_out, "%.7f, %.7f, %.7f\n", h_filt, p_filt, t_filt);
    }

    fclose(arq_in);
    fclose(arq_out);

    return 0;
}