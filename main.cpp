#include <iostream>
#include <fstream>
#include <string>
#include "Audio.h"
#include "Video.h"
using namespace std;


int main() {
    ifstream in;
    ofstream outAudio;                       
    ofstream outVideo;                       
    string dataFile = "Program5Data.txt";       
    string fileA = "audio.txt";              
    string fileV = "video.txt";              

    Media* mediaFiles[200] = {NULL};               

    int readIndex = 0;           
    int writeIndex = 0;          
    char fileType = ' ';

    in.open(dataFile);
    if (!in.is_open()) {
        cout << "Cannot open the file: " << dataFile << endl;
        return -1;
    }

    else {
        outAudio.open(fileA);           
        outVideo.open(fileV);        

        if (!outAudio.is_open() || !outVideo.is_open()) {
            cout << "Cannot open either " << fileA << " or " << fileV << endl;
            return -1;
        }
        else {
            while (in >> fileType) {
                in.ignore();           

                switch (fileType) {
                case 'A':
                    mediaFiles[readIndex] = new Audio;
                    break;
                case 'V':
                    mediaFiles[readIndex] = new Video;
                    break;
                }
                mediaFiles[readIndex]->ReadData(in);
                readIndex++;
            }
        }

        while (mediaFiles[writeIndex] != NULL
            && writeIndex <= readIndex) {

            if (mediaFiles[writeIndex]->getType() == "Audio") {
                mediaFiles[writeIndex]->WriteData(outAudio);
            }
            else {
                mediaFiles[writeIndex]->WriteData(outVideo);
            }
            writeIndex++;
        }
    }

    cout << "Please check the file audio.txt or video.txt in the same directory." << endl << endl;

    in.close();
    outAudio.close();
    outVideo.close();

    return 0;
}