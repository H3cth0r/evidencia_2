

class Server{
  private:
    string  month;      // three letter format : sep
    int     day;        // dd format
    string  hour;       // "hh:mm:ss" format
    string  ip;         // "###.###.###.###:#####" format
    string reason;      // failing reason
  public:
    Server(string month="jan", int day=1, string hour="00:00:00", string ip="192.169.1.1", string reason="save"){
      this->month   = month;
      this->day     = day;
      this->hour    = hour;
      this->ip      = ip;
      this->reason  = reason;
    }

    // GETTERS
    string getMonth(){
      return month;
    }
    int getDay(){
      return day;
    }
    string getHour(){
      return hour;
    }
    string getIp(){
      return ip;
    }
    string getReason(){
      return reason;
    }

    // SETTERS
    void setMonth(string month){
      this->month   = month;
    }
    void setDay(int day){
      this->day     = day;
    }
    void setHour(string hour){
      this->hour    = hour;
    }
    void setIp(string ip){
      this->ip      = ip;
    }
    void setReason(string reason){
      this->reason = reason;
    }
};