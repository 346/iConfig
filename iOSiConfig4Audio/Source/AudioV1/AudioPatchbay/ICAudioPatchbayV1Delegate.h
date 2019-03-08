/*
;iConfig source code and documentation is released under a GPLv3 license. 
;
; A copy is available from the Open Source Initiative site at:
;	https://opensource.org/licenses/gpl-3.0.html
*/

#import <Foundation/Foundation.h>
#import "ICPatchbayDelegate.h"
#import "DeviceInfo.h"

@interface ICAudioPatchbayV1Delegate : NSObject<ICPatchbayDelegate>

- (id)initWithDevice:(DeviceInfoPtr)device;

- (void)setCallback:(RefreshCallback)refreshCallback;

- (int)numSourceSections;
- (int)numDestinationSections;

- (int)numSourcesPerSection:(int)section;
- (int)numDestinationsPerSection:(int)section;

- (int)totalSources;
- (int)totalDestinations;

- (int)sourceIndexToTotal:(device_channel_t)targetIndex;
- (device_channel_t)sourceTotalToIndex:(int)totalInput;

- (int)destinationIndexToTotal:(device_channel_t)targetIndex;
- (device_channel_t)destinationTotalToIndex:(int)totalOutput;

- (NSString *)nameForSourceSection:(int)section;
- (NSString *)nameForDestinationSection:(int)section;

- (bool)isPatchedFrom:(device_channel_t)src to:(device_channel_t)dst;
- (void)setPatchedFrom:(device_channel_t)src to:(device_channel_t)dst andRemove:(device_channel_t)toRemove;

- (void)toggleCollapseInput:(int)section;
- (bool)isCollapsedInput:(int)section;

- (void)toggleCollapseOutput:(int)section;
- (bool)isCollapsedOutput:(int)section;

- (bool)isMixerToo;

- (void)foreach:(DevicePairOperator)deviceOperator;
- (void)foreachMixer:(DevicePairOperator)deviceOperator;

- (BOOL)isSourceDeviceInBounds:(device_channel_t)device;
- (BOOL)isDestinationDeviceInBounds:(device_channel_t)device;

@end
