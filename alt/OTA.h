#ifndef _OTA
#define _OTA

class OTA {
  public:
    OTA();

    void Beginn();
	void Bereit(bool ja);
	
	void Tick();

  private:

	bool _OTA_An; // Wurde OTA schon "angeschaltet"
};

#endif // _OTA
