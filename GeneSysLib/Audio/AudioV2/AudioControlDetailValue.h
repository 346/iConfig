/*
;iConfig source code and documentation is released under a GPLv3 license. 
;
; A copy is available from the Open Source Initiative site at:
;	https://opensource.org/licenses/gpl-3.0.html
*/

#ifndef __AUDIOCONTROLDETAILVALUE_H__
#define __AUDIOCONTROLDETAILVALUE_H__

#include "BytesCommandData.h"
#include "CommandDataKey.h"
#include "CommandDefines.h"
#include "LibTypes.h"
#include "SysexCommand.h"
#include "AudioDeviceTypes.h"
#include "property.h"
#include "ControllerType.h"
#include "AudioControlDetailValueTypes.h"

namespace GeneSysLib {

struct AudioControlDetailValue {
  static commandDataKey_t minKey();
  static commandDataKey_t maxKey();
  static commandDataKey_t queryKey(Word audioPortID, Byte controllerNumber,
                                   Byte detailNumber);
  static CmdEnum retCommand();
  static CmdEnum setCommand();

  AudioControlDetailValue();

  // overloaded methods
  const commandDataKey_t key() const;
  Bytes generate() const;
  void parse(BytesIter &begin, BytesIter &end);

  // properties
  Byte versionNumber() const;
  roWord audioPortID;
  roByte controllerNumber;
  roByte detailNumber;
  roControllerTypeEnum controllerType;

  const AudioControlDetailValueTypes::Selector &selector() const;

  AudioControlDetailValueTypes::Feature &feature();
  const AudioControlDetailValueTypes::Feature &feature() const;

  const AudioControlDetailValueTypes::ClockSource clockSource() const;

 private:
  AudioControlDetailValueTypes::Variants m_details;
};

struct GetAudioControlDetailValueCommand
    : public BytesSysexCommand<Command::GetAudioControlDetailValue> {
  GetAudioControlDetailValueCommand(DeviceID deviceID, Word transID,
                                    Word audioPortID, Byte controllerNumber,
                                    Byte detailNumber)
      : BytesSysexCommand(deviceID, transID) {
    data.append(audioPortID);
    data.append(controllerNumber);
    data.append(detailNumber);
  }
};  // GetAudioControlDetailTypes

typedef SysexCommand<Command::SetAudioControlDetailValue,
                     AudioControlDetailValue> SetAudioControlDetailValueCommand;

}  // namespace GeneSysLib

#endif  // __AUDIOCONTROLDETAILVALUE_H__
