//pinii display-ului de 4 cifre pe 7 segmente
int a = 12;
int b = 8;
int c = 5;
int d = 3;
int e = 2;
int f = 11;
int g = 6;
int p = 4;
int d4 = 7;
int d3 = 9;
int d2 = 10;
int d1 = 13;
long del = 5; 
void setup()
{
  
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  pinMode(A7, INPUT);

}
/***************************************/
void loop()
{
  int val = analogRead(A7);//citesc de la un potentiometru o valoare intre 0 si 1023
  int n = map(val, 0, 1023, 0, 9999);
  // if(n>9999)
  // n=0;
// if (del < 1)
   // del = 1;


  clearLEDs();
  cifra(0);//alimentez d1
  alegecifra((n / 1000)); // iau valoarea primei cifre
  delay(del);//5ms

  clearLEDs();//
  cifra(1);// d2
  alegecifra((n % 1000) / 100); // a doua cifra
  delay(del);// 5ms

  clearLEDs();//
 cifra(2);//d3
  alegecifra(n % 100 / 10); //a treia cifra
  delay(del);// 5ms

  clearLEDs();//
  cifra(3);//d4
  alegecifra(n % 10); //ultima cifra
  delay(del);// 5ms

 

}

void cifra(int x) //alimentez cifra x+1
{
  //display-ul are circuit cu catod comun
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);

  switch (x)
  {
    case 0:
      digitalWrite(d1, LOW);//alimenteaza cifra d1
      break;
    case 1:
      digitalWrite(d2, LOW); //alimenteaza cifra d2
      break;
    case 2:
      digitalWrite(d3, LOW); //alimenteaza cifra d3
      break;
    default:
      digitalWrite(d4, LOW); //alimenteaza cifra d4
      break;
  }
}
//se afiseaza cifra x calculata in main pe una dintre pozitiile d1-d4
void alegecifra(int x)
{
  switch (x)
  {
    default:
      zero();
      break;
    case 1:
      unu();
      break;
    case 2:
      doi();
      break;
    case 3:
      trei();
      break;
    case 4:
      patru();
      break;
    case 5:
      cinci();
      break;
    case 6:
      sase();
      break;
    case 7:
      sapte();
      break;
    case 8:
      opt();
      break;
    case 9:
      noua();
      break;
  }
}
void clearLEDs() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(p, LOW);
}

void zero() //cifra 0
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void unu() //cifra 1
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void doi() //cifra 2
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
void trei() //cifra 3
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void patru() //cifra 4
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void cinci() //cifra 5
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void sase() //cifra 6
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void sapte() //cifra  7
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void opt() //cifra  8
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void noua() //cifra 9
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

