/*
;iConfig source code and documentation is released under a GPLv3 license. 
;
; A copy is available from the Open Source Initiative site at:
;	https://opensource.org/licenses/gpl-3.0.html
*/

#ifndef __AUDIOPATCHBAYSOURCEV2_H__
#define __AUDIOPATCHBAYSOURCEV2_H__

#include "DeviceInfo.h"
#include "IAudioPatchbaySource.h"
#include "CommandQList.h"
#include "MixerRelated/MixerInterface.h"

struct AudioPatchbaySourceV2 : public IAudioPatchbaySource {
  static CommandQList Query();

  AudioPatchbaySourceV2(DeviceInfoPtr deviceInfo);

  void init(const boost::function<void(void)> &refreshCallback);
  int numSections() const;

  int numInputsPerSection(int section) const;
  int numOutputsPerSection(int) const;

  QString nameForSection(int section) const;

  bool isPatched(device_port_t srd, device_port_t dest) const;
  void setPatch(device_port_t src, device_port_t dest, device_port_t toRemove);

  void toggleCollapseInput(int section);
  bool isCollapsedInput(int section) const;

  void toggleCollapseOutput(int section);
  bool isCollapsedOutput(int section) const;

  bool isMixerToo() const;

  void for_each_mixer(const boost::function<void(const device_pair_t &)> &func) const;
  void for_each(const boost::function<void(const device_pair_t &)> &func) const;

 private:
  channel_map_t channelMap;
  DeviceInfoPtr device;
  MixerInterface* mixerInterface;
  bool isMixerTooBool;
  std::vector<bool> isCollapsedInputVec;
  std::vector<bool> isCollapsedOutputVec;
};

#endif  // __AUDIOPATCHBAYSOURCEV2_H__
