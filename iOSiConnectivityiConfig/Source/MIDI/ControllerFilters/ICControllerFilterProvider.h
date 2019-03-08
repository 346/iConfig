/*
;iConfig source code and documentation is released under a GPLv3 license. 
;
; A copy is available from the Open Source Initiative site at:
;	https://opensource.org/licenses/gpl-3.0.html
*/

#import "ICDefaultProvider.h"

#include "MIDIPortFilter.h"

#include <boost/function.hpp>
#include <map>

@interface ICControllerFilterProvider : ICDefaultProvider {
  BOOL isInput;
  int filterID;
  GeneSysLib::FilterIDEnum filterType;
  NSArray *buttonNames;
  Word portID;

  std::map<int, boost::function<void(BOOL)> > setMap;
  std::map<int, boost::function<BOOL(void)> > getMap;

  NSString *title;
}

- (id)initWithDevice:(DeviceInfoPtr)device
            forInput:(BOOL)inputType
              portID:(Word)_portID
         forFilterID:(int)_filterID;

@end
