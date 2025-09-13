# ⚽ IoT Smart Scoreboard – Passa Bola

Projeto de IoT desenvolvido para a Sprint do Passa Bola na disciplina de Edge Computing and Computer Systems da FIAP.

## 📝 Descrição do Projeto

Este projeto traz a experiência de um placar inteligente para partidas amadoras de futebol de mesa, utilizando IoT e automação para detecção de gols em tempo real.

Utilizando o ESP32, criamos um sensor de gol com contador integrado e botão para anular gols. O objetivo é permitir a detecção automática de gols, trazendo mais tecnologia e precisão para partidas amadoras.

A detecção ocorre quando a bola atravessa uma barreira infravermelha (IR), acionando a exibição do placar em um display LCD I2C, que mostra em tempo real o número de gols marcados. O evento também pode ser anulado com um botão de anular gol.

Cada gol detectado é enviado automaticamente para um servidor, que atualiza o placar em tempo real. Esse placar pode ser incorporado a transmissões ao vivo ou exibido no site do Passa Bola, proporcionando uma experiência semelhante à de jogos profissionais e aumentando o engajamento do público.

## 🎯 Escopo

- Protótipo com ESP32, sensor de barreira IR, LCD I2C e um Botão;
- Simulação fiel no Wokwi com possibilidade de migração para hardware real sem alterações significativas;
- Integração opcional com servidor (HTTP/MQTT) e dashboard em tempo real usando Node-Red.

## ✅ Objetivos Entregáveis

- Firmware funcional para ESP32 (código-fonte);
- Instruções para simulação no Wokwi e execução no hardware;
- Código do servidor simples e dashboard (opcional);
- Plano de testes e critérios de aceitação.

## 🏆 Critérios de Aceitação

### Requisitos Obrigatórios
- Ao atravessar a barreira IR, o sistema registra um gol e incrementa o placar;
- O botão pode ser pressionado para anular o último gol;
- Registro legível no LCD I2C;

### Requisito Opcional
- Evento enviado ao servidor e refletido no dashboard em menos de 2 segundos.

## 🏗️ Arquitetura Proposta
A arquitetura do projeto foi desenhada para integrar sensores físicos, processamento em tempo real e visualização dos dados em um painel de controle.

- 🛰️ Sensores IoT (IR): detectam quando a bola cruza a linha do gol;
- 📡 MQTT Broker (Mosquitto): atua como intermediário para receber e distribuir as mensagens publicadas pelos sensores;
- 🔄 Node-RED: orquestra o fluxo de dados, processando os eventos recebidos via MQTT, atualizando o placar e enviando comandos de volta para o display;
- 📊 Dashboard (Node-RED Dashboard): fornece uma interface gráfica acessível via navegador, permitindo acompanhar os gols em tempo real;
- 🖥️ Display LCD I2C: funciona como atuador, exibindo o placar físico atualizado conforme os dados processados no Node-RED.

Toda essa infraestrutura roda em containers Docker, facilitando a instalação, configuração e portabilidade do sistema.

<div align="center">
  
  ![Infraestrutura do Servidor](./Arquitetura%20IoT%20Fiware.png)
  
</div>


## 🧰 Componentes Utilizados

- Sensor IR (2)
- ESP32
- Botão
- LCD I2C
- Jumpers

### Explicação dos Componentes

- **Sensor IR (barreira):** Detecta a interrupção do feixe quando a bola passa. Normalmente conectado como entrada digital; muitos módulos retornam LOW quando o feixe é interrompido;
- **ESP32:** Microcontrolador que lê o sensor, aplica debounce/filtragem, incrementa contadores e (opcional) envia eventos ao servidor via Wi-Fi;
- **Botão:** Ação local para imediata anulação do gol;
- **LCD I2C:** Visualização de eventos durante o desenvolvimento.

## 🛠️ Recursos Necessários

### Hardware (Simulação no Wokwi)

- ESP32 Dev Module;
- Sensor de barreira IR (ou sensor digital equivalente);
- Botão;
- LCD I2C;
- Cabos jumper (M-M/F-M conforme necessidade).

### Hardware (Versão Física)

- O mesmo que na simulação Wokwi;
- Cabo USB A→Micro/USB-C;
- Fonte / Power Bank.

### Software / Ferramentas

- Wokwi (simulação);
- Arduino IDE (ou PlatformIO) com suporte a ESP32;
- Node-Red (para servidor e dashboard, rodando em máquina virtual com FIWARE via Docker Compose);
- Navegador moderno para dashboard (opcional).

### Bibliotecas Recomendadas

- WiFi.h (ESP32);
- HTTPClient.h (para chamadas HTTP);
- PubSubClient (opcional, para MQTT);
- ESPAsyncWebServer (opcional, para servidor no próprio ESP32);
- LiquidCrystal_I2C.h (para LCD I2C).

## ▶️ Instruções de Uso

### 1) Simulação no Wokwi

- Abra o link: [👉 Simulação Wokwi](https://wokwi.com/projects/441846636237669377);
- Clique em "Start Simulation";
- Para simular o passe da bola, ative o sensor (há controles para togglar o pino) ou use o painel de simulação;
- Observe as mensagens no LCD I2C.

### 2) Integração com Servidor 

- Utilize o Node-Red como servidor e dashboard, rodando em uma máquina virtual com FIWARE montado via Docker Compose;
- O Node-RED roda em container Docker e é acessível pela porta 1880, enquanto o Mosquitto (broker MQTT) pela porta 1883.
- Configure os fluxos no Node-Red para receber eventos via HTTP POST ou MQTT e atualizar a interface em tempo real;
- Atualize o firmware do ESP32 para enviar POSTs ao endpoint do Node-Red ou conectar via MQTT conforme configurado.

## 📄 Arquivo código-fonte

Todo o funcionamento do sistema de monitoramento com IRs, botão e display LCD I2C está implementado no código ESP32 a seguir:

[👉 Visualizar código no GitHub](./codigo_fonte.cpp)

## 👥 Integrantes do Grupo

| [<img loading="lazy" src="https://github.com/DaviMunhoz1005.png" width=115><br><sub>Davi Marques</sub>](https://github.com/DaviMunhoz1005) |  [<img loading="lazy" src="https://github.com/Gabsgc01.png" width=115><br><sub>Gabriel Ciriaco</sub>](https://github.com/Gabsgc01) | [<img loading="lazy" src="https://github.com/MariFranca.png" width=115><br><sub>Mariana Souza</sub>](https://github.com/MariFranca) | [<img loading="lazy" src="https://github.com/larissashiba.png" width=115><br><sub>Larissa Shiba</sub>](https://github.com/larissashiba) | [<img loading="lazy" src="https://github.com/Mafraaa.png" width=115><br><sub>Vinicius Mafra</sub>](https://github.com/Mafraaa) | 
| :---: | :---: | :---: | :---: | :---: |
