/*
  ==============================================================================

    Synth.h
    Created: 26 Feb 2023 11:12:21pm
    Author:  DTM

  ==============================================================================
*/

#pragma once

#include "SineOSC.h"

//名前空間を設けておく、理由は後述

namespace synth
{
    class Synth{
    public:
        //midi入力をOscに伝える
        void midiProcessing(juce::MidiMessage&, double hostSampleRate);
        //Oscから波形データをhostのAudioBufferに書き下す
        void renderWaveData(float* hostAudioBuffer, int bufferSize);

    private:
        SineOSC oscillator;
    };

    //一連のmidi処理、audio処理を行う
    //ProcessBlockで呼び出す
    //SynthClass内に設けないのは"Effective C++ 第3版"の23項に倣って
void doProcessing(Synth&, juce::AudioSampleBuffer&, juce::MidiBuffer&, double hostSampleRate);
}

//Synth.cpp===========================================================================
