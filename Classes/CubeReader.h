#ifndef __CUBE_READER_H__
#define __CUBE_READER_H__

class CubeReader {
    private:
        char cube[45];      // 5 * 9
        int timeOut;
        int threshold;

        void readCube();

    public:
        CubeReader(const char *mapName);

        char* getCube();

        int getTimeOut();
        int getThreshold();

    protected:
        ~CubeReader() {}
};

#endif // __CUBE_READER_H__
