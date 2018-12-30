#ifndef _INCLUDE_MQTT_ADATOR
#define _INCLUDE_MQTT_ADATOR

class MQTT_Adaptor {
	public:
	MQTT_Adaptor();
	void Beginn();
	bool Verbunden();
	bool Verbinde(const char*ClientID, const char* User, const char* PW);
	void Tick();
  bool Publish(const char topic[], const char payload[], bool retained = false, int qos = 0);
	bool Subscribe(const char *Thema);
	bool Unsubscribe(const char *Thema);
	int Status();
};
#endif // _INCLUDE_MQTT_ADAPTOR
