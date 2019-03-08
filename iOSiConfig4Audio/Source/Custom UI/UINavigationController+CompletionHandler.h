/*
;iConfig source code and documentation is released under a GPLv3 license. 
;
; A copy is available from the Open Source Initiative site at:
;	https://opensource.org/licenses/gpl-3.0.html
*/

#import <UIKit/UIKit.h>

@interface UINavigationController (CompletionHandler)

- (void)completionhandler_popViewControllerAnimated:(BOOL)animated
                                         completion:(void (^)(void))completion;

@end
