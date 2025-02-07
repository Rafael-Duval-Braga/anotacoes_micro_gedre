# micro gedre
O que fazer:

## 1° Ler o datasheet do 579-PIC16F1769-I/SS

### Ver os componentes que tenho que colocar ao redor do chip
- [ ] Anotações
- Pinagem na pg(4)
- Applications: Switch-mode power supplies (DC-to-DC/AC-to-DC)
- Tensão de alimentação - 2.5 V to 5.5 V
#### classificações maximas absolutas pg(478)

### Anotações do que achei na pg(462)
#### Five pins are needed for ICSP™ programming:
- obs: eu falei com o renan e realmente, é nessa pagina que esta os pinos de conecção para o pickit, alias ele me passou um desenho bem como um esquematico sobre o que mais ou menos ele esta desejando para ser feito deixei anotações sobre isso nos links
- ICSPCLK
- ICSPDAT
- MCLR/VPP
- VDD
- VSS
- pino para o sinal PWM 

- [ ] Links
      
- site do fabricante: <https://br.mouser.com/ProductDetail/Microchip-Technology/PIC16F1769-I-SS?qs=4f%252Bx0JRcgJZxCFgtF0sYlg%3D%3D&srsltid=AfmBOooehqHrvz6JPwbJgqptTAqiJM8v0NAbV50qgQvy_N7ubH63BWmr>
  
- datasheet: <https://br.mouser.com/datasheet/2/268/PIC16(L)F1764-5-8-9-14-20-Pin-8-Bit-Flash-MCU-4000-1314189.pdf> (obs: esse daqui não possui typical circuit) / professor falou que
na parte da conecção com o debugger aparece o esquematico, acho que é o da pg(462), é literalmente o mesmo chip, mesma estrutura

- “ For more information on ICSP™ refer to the 'PIC16(L)F170X Memory Programming Specification'”: <https://ww1.microchip.com/downloads/en/DeviceDoc/40001683B.pdf>

- datasheet que o professor passou em que mostra um circuito que exemplifica o que ele quer, se encontra dentre os circuitos da pg(19) (é o circuito conectado ao chip u4 do lado do led d2 green que alias o professor pediu para adicionar tambem para ver se a placa esta ou não ligada): <https://ww1.microchip.com/downloads/en/DeviceDoc/Curiosity-Low-Pin-Count-Development-Board-Users-Guide-40001804D.pdf>
  
## 2° Ler o datasheet do microship pickit 5
### Ver os conectores que tenho que colocar no gravador/depurador + os sinais que ele emite
- [ ] Anotações

- todo
- [ ] ler o manual do pic-16f628A
- site do fabricante: <https://www.microchip.com/en-us/product/pic16f628a>
- datasheet: <https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40044G.pdf>
- obs: acho que na pag 114 monstra os pinos p/ programar. 99% de certeza ao comparar a pag 114 desse manual com a pag 463 do pic-16F1769
- conferir quanto de tensão colocar no gnd & vcc
- [ ] montar o chip na protoboard
- [ ] conectar o pikit 5 na protoboard
- [ ] aprender como usar o mplab x ide
- Blinky and Running LEDs 🔴 PIC Microcontroller Programming Tutorial #3 MPLAB in C: <https://youtu.be/OBNpr4BSHA8?feature=shared>
- [ ] montar a placa do pic-16f1769
- [ ] testar na placa
      

- [ ] Links
- site do fabricante: <https://www.microchip.com/en-us/development-tool/PG164150>
- datasheet: <https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/UserGuides/MPLAB-PICkit-5-In-Circuit-Debugger-Users-Guide-50003525.pdf#page=13&zoom=100,0,253>
- Aula 003 - Criando e compilando projetos com o MPLAB X e o compilador XC8: <https://www.youtube.com/watch?v=KUDuht_tzDg>
- Como criar um novo projeto no MPLAB X | PIC #04: <https://youtu.be/g0kYKjXIjD0?si=mNOoakweSEjs0gsK>
- Getting Started with PICKit 5 - Setting Up Your First Project: <https://youtu.be/AZxia-ey7Dw?si=GqMDZY75jTHdKAm3>




## links extras:
- "From Idea to Schematic to PCB - <How to do it easily!": https://youtu.be/35YuILUlfGs?si=2a0s9VaXoEdnJa0E>
- "PCB Creation for Beginners - Start to finish tutorial in 10 minutes" <https://youtu.be/MsdJgEinb34?si=JU-Bc_eQL__jkyqd>
- "How To Read A Datasheet - Phil's Lab #123": <https://youtu.be/1EXXqWweTkI?si=hWDz0JQ2FpIgRCck>

## Link do atlium 365:
- <https://rafael-braga.365.altium.com/designs/D490ACA9-A712-4FE8-9F94-6172F4BF13D2#design>
## Link do easy eda:
- <https://easyeda.com/editor#id=a2d0c3f24be84ffcb68d1d5a96755303|070f6bd9a66b46cd97a30692144fba46>

## Obs:
- O circuito do micro deve ser padronizado para os outros bucks
- [x] ver qual pino do chip envia o sinal PWM (na pagina 253 do datasheet aparece as configurações do PWM)
- [ ] ver como vão ser os outros bucks
- [x] ver quais componentes são controlados pelo micro 
- [x] ver se há placas com funcionalidades semelhantes ao que busco com o micro

## todo

- [x] comparar o chip u4 (PIC16F18446-I/SO) da página 19 do 4° link com o chip PIC16f1769
      - eu comparei com a pinagem nesses dois links <https://br.mouser.com/ProductDetail/Microchip-Technology/PIC16F18446-I-SO?qs=rrS6PyfT74fKS3ku0yMz%252Bg%3D%3D&utm_id=12168397652&gad_source=1&gclid=EAIaIQobChMI75KrvvzoiQMVF9cWBR1C4xHSEAAYAyAAEgI14PD_BwE> & <https://br.mouser.com/ProductDetail/Microchip-Technology/PIC16F1769-I-SS?qs=4f%252Bx0JRcgJZxCFgtF0sYlg%3D%3D&srsltid=AfmBOorJ7OEVpVLfdzuGaZaQELkCJcCpsSGb6BPpS4Pniy5SPgeyJCLt>
- [x] achar uma biblioteca para colocar no altium, para fazer o circuito (achado na página 19 do 4° link). Tem o micro que vamos usar (PIC16F1769-I/SS) (ir em panels/ manufactured part search/ pesquisar "PIC16F1769" na barra de pesquisa dai acha o micro
- [x] colocar os pinos (jumpers) (pin header) j9 & j11
- [x] colocar o led que indica que ta ligado
- [x] colocar o capacitor
- [x] colocar os resistores

      











