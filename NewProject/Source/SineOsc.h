/*
  ==============================================================================

    SineOsc.h
    Created: 26 Feb 2023 11:12:44pm
    Author:  DTM

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SineOSC{
public:
    void midiOn(int midiNoteNum,double hostSampleRate);
    void midiOff();
    double Get();
    void phaseIncrement();
    
private:
    bool _midiInput=false;
    double _n = 0;
    double _f = 440;
    double _p = 100;
};
