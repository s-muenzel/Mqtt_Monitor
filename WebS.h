#ifndef _WEBS
#define _WEBS


class WebS {
  public:
    WebS();
    void Beginn();
    void Admin_Mode(bool ja = true);
    void Tick();
  private:
    bool AutoUpdate;
};

#endif // _WEBS
