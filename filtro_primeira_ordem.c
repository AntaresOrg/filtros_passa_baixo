#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_DADOS_POR_LINHA 3
#define PI 3.141592653589793

double calcular_alpha(double fc, double fs) {
    double dt = 1.0 / fs;
    return (2.0 * PI * fc * dt) / (1.0 + 2.0 * PI * fc * dt);
}

double filtro_passa_baixo(double leitura_atual, double ultima_saida, double alpha) {
    return (alpha * leitura_atual) + (1.0 - alpha) * ultima_saida;
}

int main() {

    double fs = 100.0;
    double fc = 17.0;

    double alpha = calcular_alpha(fc, fs);

    double height_lida, pressure_lida, temperature_lida;
    double media_height, media_pressure, media_temperature;

    FILE *arquivo_entrada = fopen("dados.txt", "r");
    if (!arquivo_entrada) {
        perror("Erro ao abrir dados.txt");
        return 1;
    }

    FILE *arquivo_saida = fopen("output.txt", "w");
    if (!arquivo_saida) {
        perror("Erro ao criar output.txt");
        fclose(arquivo_entrada);
        return 1;
    }

    fprintf(arquivo_saida, "ALTURA_FILTRADA, PRESSAO_FILTRADA, TEMPERATURA_FILTRADA\n");

    if (fscanf(arquivo_entrada, "%lf %lf %lf", &height_lida, &pressure_lida, &temperature_lida) == NUM_DADOS_POR_LINHA) {
        media_height = height_lida;
        media_pressure = pressure_lida;
        media_temperature = temperature_lida;

        fprintf(arquivo_saida, "%.7lf, %.7lf, %.7lf\n", media_height, media_pressure, media_temperature);
    }

    while (fscanf(arquivo_entrada, "%lf %lf %lf", &height_lida, &pressure_lida, &temperature_lida) == NUM_DADOS_POR_LINHA) {

        media_height = filtro_passa_baixo(height_lida, media_height, alpha);
        media_pressure = filtro_passa_baixo(pressure_lida, media_pressure, alpha);
        media_temperature = filtro_passa_baixo(temperature_lida, media_temperature, alpha);

        fprintf(arquivo_saida, "%.7lf, %.7lf, %.7lf\n", media_height, media_pressure, media_temperature);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}