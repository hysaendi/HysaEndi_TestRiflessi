int  ledBlu; //led primotest
int buzzer; //secondo test
int rgb_Rosso; //led che cambia colore
int rgb_Verde; 
int tempoTestIn;  //tempo prova led blu
int tempoTestBuzz;  //tempo prova buzzer
int bottone;//bottone per esecuzione primo test
int statoBottone; //stato del bottone: HIGH o LOW




void setup() {
  // put your setup code here, to run once:
  bottone = 3;
  ledBlu = 4;
  buzzer = 5;
  rgb_Rosso = 8;
  rgb_Verde;
  
  
 pinMode (bottone,INPUT);
 pinMode (ledBlu, OUTPUT);
 pinMode (buzzer, OUTPUT);
 pinMode (rgb_Rosso, OUTPUT);
 pinMode (rgb_Verde, OUTPUT);
  
  

}  

void loop() {
  // put your main code here, to run repeatedly:
   premerePulsante();  //il programma parte con la pressione del bottone
   tempoTestIn = esecuzioneTest (ledBlu, "Lasso di tempo riguardante il test visivo:");
   tempoTestBuzz = esecuzioneTest (buzzer, "Lasso di tempo riguardante il test uditivo:");
   verificaTest (tempoTestIn,tempoTestBuzz,rgb_Verde,rgb_Rosso);
  
   

}

void premerePulsante()
{ statoBottone = digitalRead (bottone); //variabile di appoggio
  statoBottone = HIGH;
}

int esecuzioneTest (int oggetto, String messaggio)
{
  int tempoUno;
  int tempoTestTot;
  delay (random(500,8000));
  digitalWrite (oggetto,HIGH);
  tempoTestIn = millis(); //restituisce il tempo trascorso fino a quando non premo il pulsante
  premerePulsante();
  digitalWrite (oggetto,LOW);
  int tempoDue; //dichiaro il secondo test
  delay (random(500,8000));
  digitalWrite (oggetto,HIGH);
  tempoTestBuzz = millis();
  tempoTestTot = tempoUno + tempoDue;
  Serial.println (messaggio + String(tempoTestTot));
}

void verificaTest (int tempoTestIn, int tempoTestBuzz , int testSuperato, int testNonSuperato)
{
  //con test superato e non superato intendo di che colore il led rgb si dovrà colorare ( verde = test superato / rosso = test non superato)
  if (tempoTestIn > 250 && tempoTestBuzz > 250)
  {
    digitalWrite (testNonSuperato,HIGH);
  }
  else
  {
    digitalWrite (testSuperato,HIGH);
  }
  digitalWrite (testSuperato,LOW);  //spengo i 2 led rgb
  digitalWrite (testNonSuperato,LOW);
}
