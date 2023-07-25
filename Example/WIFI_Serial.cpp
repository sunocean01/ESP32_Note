#include<WiFi.h>


const char* ssid="SensirionMA";   //定义两个字符串指针常量
const char* password="W1Fi4Employ33";

void setup() {
	Serial.begin(115200);
	
	while (!Serial) delay(10); // will pause Zero, Leonardo, etc until serial console opens

	// We start by connecting to a WiFi network
	Serial.println();
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("WiFi connected.");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());


	Wire.begin(12, 14);       //Redesign the I2C pin.
	Serial.println("Adafruit SCD30 test!");

	// Try to initialize!
	if (!scd30.begin()) {
	Serial.println("Failed to find SCD30 chip");
	while (1) { delay(10); }
	}
	Serial.println("SCD30 Found!");

	// if (!scd30.setMeasurementInterval(10)){
	//   Serial.println("Failed to set measurement interval");
	//   while(1){ delay(10);}
	// }
	Serial.print("Measurement Interval: "); 
	Serial.print(scd30.getMeasurementInterval()); 
	Serial.println(" seconds");


}

void loop() {
	if (scd30.dataReady()){
	Serial.println("Data available!");

	if (!scd30.read()){ Serial.println("Error reading sensor data"); return; }

	Serial.print("Temperature: ");
	Serial.print(scd30.temperature);
	Serial.println(" degrees C");

	Serial.print("Relative Humidity: ");
	Serial.print(scd30.relative_humidity);
	Serial.println(" %");

	Serial.print("CO2: ");
	Serial.print(scd30.CO2, 3);
	Serial.println(" ppm");
	Serial.println("");
	} else {
	//Serial.println("No data");
	}

	delay(100);


}
