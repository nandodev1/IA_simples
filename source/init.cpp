void setup()
{

}

float y = 0;

void loop()
{
    y += 0.1;
    retangulo( 300, y, 15.0, 15.0, { 100, 250, 50});
    retangulo( 100, y+ 50, 15.0, 15.0, { 100, 50, 50});
    retangulo( y, y+ 50, 15.0, 15.0, { 100, 150, 50});
	
}
    