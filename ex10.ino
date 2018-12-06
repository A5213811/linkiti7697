＃包括 < DHT.h >
＃包括 < LiquidCrystal_I2C.h >

DHT dht（4，DHT11）;
LiquidCrystal_I2C lcd_i2c（0x27）;

void  setup（）
{
  串行。開始（9600）;
  DHT。begin（）;
  lcd_i2c。開始（16，2）;
  pinMode（3，INPUT）;
  lcd_i2c。clear（）;
}

void  loop（）
{
  串行。print（“溫度= ”）;
  串行。println（dht.readTemperature（））;
  串行。print（“濕度= ”）;
  串行。println（dht.readHumidity（））;
  串行。print（“土壤濕度= ”）;
  串行。println（analogRead（14））;
  
  lcd_i2c。的setCursor（0，0）;
  lcd_i2c。print（“ T = ”）;
  lcd_i2c。的setCursor（2，0）;
  lcd_i2c。print（dht.readTemperature（））;
  lcd_i2c。的setCursor（8，0）;
  lcd_i2c。print（“ H = ”）;
  lcd_i2c。的setCursor（10，0）;
  lcd_i2c。print（dht.readHumidity（））;

  lcd_i2c。的setCursor（0，1）;
  lcd_i2c。print（“ SM = ”）;
  lcd_i2c。的setCursor（3，1）;
  lcd_i2c。print（analogRead（14））;
  
  延遲（1000）;
}
