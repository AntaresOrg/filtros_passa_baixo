<img width="1080" height="597" alt="image" src="https://github.com/user-attachments/assets/1bdff07d-5037-45ca-a38a-f27567c361b8" />

Basicamente, o filtro passa baixo de segunda ordem faz uso da transformada em Z, isto é, utiliza amostras anteriores. Assim, o código precisaria armazenar estados anteriores 
Na imagem, nota-se que o símbolo X representa multiplicação e o símbolo + representa soma. Ademais, a0, a1, b0 são constantes.
Assim, 

<img width="652" height="52" alt="image" src="https://github.com/user-attachments/assets/323770d6-3a32-47f4-8d1c-d7316a4c4c02" />

Onde Y é o dado filtrado, X é o dado antes de ser filtrado e [n-1] e n[-2] indicam dados “antigos”
Assim, precisaria armazenar os estados Y anteriores ([n-1] e [n-2]). Entretanto, é possível deixar o Y de maneira implícita com o uso da estrutura Direct Form II Transposta (DF2T)

<img width="375" height="105" alt="image" src="https://github.com/user-attachments/assets/4c353463-11e9-4c8d-be8a-e3073ef02a60" />

Dessa forma, é necessário salvar apenas x[n] e w[n] enquanto y[n] é encaminhado para o arquivo .txt

CONSTANTES
a0​ = 1+α

<img width="106" height="42" alt="image" src="https://github.com/user-attachments/assets/b497009e-4823-4707-a4ef-137e1bed103f" />

<img width="106" height="40" alt="image" src="https://github.com/user-attachments/assets/8a273d25-cd06-498f-b6ac-6c032fb54d0f" />

<img width="106" height="42" alt="image" src="https://github.com/user-attachments/assets/a7f8d8b6-3e6a-479d-b612-75299fbaf91a" />

<img width="106" height="42" alt="image" src="https://github.com/user-attachments/assets/7e9327ba-638b-48cc-909f-1f4b6ac86d0f" />

<img width="78" height="40" alt="image" src="https://github.com/user-attachments/assets/0674b74e-bd34-4f66-b6b7-93cde4416836" />
