
#ifndef __Request_hpp
#define __Request_hpp

class Request {
public:
    Request(double rTime, int rTrack, int rSector, int rIndex):  _time(rTime), _track(rTrack), _sector(rSector), _index(rIndex) {}

    int track()    { return _track;  }
    int sector()   { return _sector; }
    double time()  { return _time;   }
    int index()    { return _index;  }

private:
    double _time;
    int _track, _sector;
    int _index;

};

#endif
