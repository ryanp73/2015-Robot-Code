/*	My custom header file. Only two functions	*/

//	Some variable I don't use, but is necessary
int offset = 598;

//	Awesome speed curve equation, don't question how this works
int speedCurve(int x)
{
	float speed = 0.0000216166*pow(x,3)+1.19001*pow(10,-18)*pow(x,2)+0.427083*x;
	return speed;
}

//	Some gyro code
void calibrateGyro(tSensors gyro)
{
	int total = 0;
	for(int i = 0; i < 5; i++)
	{
		total += SensorValue(gyro);
	}
	offset = total / 5;
}
