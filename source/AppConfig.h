/*
  =================================================================

  This file is part of the Measuring LUFS program.
  Copyright (c) 2014 - Mathieu Pavageau - contact@repetito.com

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  Details of these licenses can be found at: www.gnu.org/licenses

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  =================================================================
*/

#ifndef __LUFS_APPCONFIG_H__
#define __LUFS_APPCONFIG_H__

// Juce definitions, to be included by Juce module files

#define JUCE_DONT_ASSERT_ON_GLSL_COMPILE_ERROR 1
#define JUCE_ENABLE_REPAINT_DEBUGGING 0

#define JUCE_MODULE_AVAILABLE_juce_audio_basics          1
#define JUCE_MODULE_AVAILABLE_juce_audio_devices         1
#define JUCE_MODULE_AVAILABLE_juce_audio_formats         1
#define JUCE_MODULE_AVAILABLE_juce_audio_plugin_client   1
#define JUCE_MODULE_AVAILABLE_juce_audio_processors      1
#define JUCE_MODULE_AVAILABLE_juce_audio_utils           1
#define JUCE_MODULE_AVAILABLE_juce_core                  1
#define JUCE_MODULE_AVAILABLE_juce_cryptography          1
#define JUCE_MODULE_AVAILABLE_juce_data_structures       1
#define JUCE_MODULE_AVAILABLE_juce_events                1
#define JUCE_MODULE_AVAILABLE_juce_graphics              1
#define JUCE_MODULE_AVAILABLE_juce_gui_basics            1
#define JUCE_MODULE_AVAILABLE_juce_gui_extra             1
#define JUCE_MODULE_AVAILABLE_juce_opengl                0
#define JUCE_MODULE_AVAILABLE_juce_video                 0

#ifdef USING_ASIO
#define JUCE_ASIO 1
#endif 

#define JUCE_WASAPI 1
//#define JUCE_DIRECTSOUND 1
//#define JUCE_ALSA 1
//#define JUCE_JACK 1
//#define JUCE_PLUGINHOST_VST3 1

#define JucePlugin_Name "Measuring LUFS"
#define JucePlugin_Version                1.0.0
#define JucePlugin_VersionCode            0x10000
#define JucePlugin_VersionString          "1.0.0"

#if defined ( MEASURING_LUFS_PLUGIN )

#if defined ( MEASURING_LUFS_APPLICATION )
#error ( "Either MEASURING_LUFS_PLUGIN or MEASURING_LUFS_APPLICATION must be defined" )
#endif 

#define JUCE_VST3_CAN_REPLACE_VST2 0

#define JUCE_PLUGINHOST_VST 0
//#define JUCE_PLUGINHOST_AU 0

//==============================================================================
// Audio plugin settings..


//==============================================================================
// Audio plugin settings..

#define JucePlugin_Build_VST 1
#define JucePlugin_Build_VST3 1
#define JucePlugin_Build_AU               1
#define JucePlugin_Build_RTAS             0
#define JucePlugin_Build_AAX              0

#define JucePlugin_PluginCode             'mluf'
#define JucePlugin_Manufacturer           "Mathieu Pavageau"
#define JucePlugin_ManufacturerCode       'mpav'
//#define MLUFS_TESTING_STEREO
#ifdef MLUFS_TESTING_STEREO
#pragma message ( "MLUFS_TESTING_STEREO" )
    #define JucePlugin_MaxNumInputChannels    2
    #define JucePlugin_MaxNumOutputChannels   2
    #define JucePlugin_PreferredChannelConfigurations  {1, 1}, {2, 2}
#else
    #define JucePlugin_MaxNumInputChannels    6
    #define JucePlugin_MaxNumOutputChannels   6
    #define JucePlugin_PreferredChannelConfigurations  {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}
#endif 
#define JucePlugin_IsSynth                0
#define JucePlugin_WantsMidiInput         0
#define JucePlugin_ProducesMidiOutput     0
#define JucePlugin_SilenceInProducesSilenceOut  0
#define JucePlugin_EditorRequiresKeyboardFocus  0
#define JucePlugin_VSTUniqueID            JucePlugin_PluginCode
#define JucePlugin_VSTCategory            kPlugCategAnalysis
#define JucePlugin_AUMainType             kAudioUnitType_MusicEffect
#define JucePlugin_AUSubType              JucePlugin_PluginCode
#define JucePlugin_AUExportPrefix         MLUFSProjectAU
#define JucePlugin_AUExportPrefixQuoted   "MLUFSProjectAU"
#define JucePlugin_AUManufacturerCode     JucePlugin_ManufacturerCode
#define JucePlugin_CFBundleIdentifier     com.mathieupavageau.mulfs
#define JucePlugin_RTASCategory           ePlugInCategory_None
#define JucePlugin_RTASManufacturerCode   JucePlugin_ManufacturerCode
#define JucePlugin_RTASProductId          JucePlugin_PluginCode
#define JucePlugin_RTASDisableBypass      0
#define JucePlugin_RTASDisableMultiMono   0
#define JucePlugin_AAXIdentifier          com.mathieupavageau.MulfsPlugin
#define JucePlugin_AAXManufacturerCode    JucePlugin_ManufacturerCode
#define JucePlugin_AAXProductId           JucePlugin_PluginCode
#define JucePlugin_AAXPluginId            JucePlugin_PluginCode
#define JucePlugin_AAXCategory            AAX_ePlugInCategory_Dynamics
#define JucePlugin_AAXDisableBypass       0

#else // defined ( MEASURING_LUFS_PLUGIN )

#if !defined ( MEASURING_LUFS_APPLICATION )
#error ( "Either MEASURING_LUFS_PLUGIN or MEASURING_LUFS_APPLICATION must be defined" )
#endif 

#endif // defined ( MEASURING_LUFS_PLUGIN )

#endif // __LUFS_APPCONFIG_H__