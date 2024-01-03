/*
  ==============================================================================

    SineOsc.cpp
    Created: 26 Feb 2023 11:12:44pm
    Author:  DTM

  ==============================================================================
*/

#include "SineOsc.h"

void SineOSC::midiOn(int midiNoteNum, double hostSampleRate) {
    _midiInput = true;
    _n =0;
    _f = juce::MidiMessage::getMidiNoteInHertz(midiNoteNum);
    _p = hostSampleRate / _f;
    
};

void SineOSC::midiOff(){
    _midiInput = false;
};

double SineOSC::Get(){
    if(!_midiInput){return 0.0;}
    
    return sin(2.0 * juce::MathConstants<double>::pi * _n/_p);
};

void SineOSC::phaseIncrement(){
    if(++_n >= _p){_n = _n - int(_n / _p)*_p;}
}





