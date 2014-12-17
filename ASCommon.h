#import <UIKit/UIKit.h>
#import "SBIcon.h"
#import "SBIconView.h"
#import "SBAppSwitcherSnapshotView.h"

typedef NS_ENUM(NSInteger, ASAuthenticationAlertType) {
  ASAuthenticationAlertAppArranging,
  ASAuthenticationAlertSwitcher,
  ASAuthenticationAlertSpotlight,
  ASAuthenticationAlertPowerDown,
  ASAuthenticationAlertControlCentre
};

typedef void (^ASCommonAuthenticationHandler) (BOOL wasCancelled);

@interface ASCommon : NSObject
@property (readonly) NSMutableArray *snapshotViews;
@property (readonly) NSMutableArray *obscurityViews;
+(instancetype)sharedInstance;
-(UIAlertView *)createAppAuthenticationAlertWithIconView:(SBIconView *)iconView beginMesaMonitoringBeforeShowing:(BOOL)shouldBeginMonitoringOnWillPresent vibrateOnIncorrectFingerprint:(BOOL)vibrateOnBadFinger dismissedHandler:(ASCommonAuthenticationHandler)handler;
-(UIAlertView *)createAuthenticationAlertOfType:(ASAuthenticationAlertType)alertType beginMesaMonitoringBeforeShowing:(BOOL)shouldBeginMonitoringOnWillPresent vibrateOnIncorrectFingerprint:(BOOL)vibrateOnBadFinger dismissedHandler:(ASCommonAuthenticationHandler)handler;
-(BOOL)isTouchIDDevice;
-(BOOL)shouldAddObscurityViewForSnapshotView:(SBAppSwitcherSnapshotView *)snapshotView;
-(UIView *)obscurityViewForSnapshotView:(SBAppSwitcherSnapshotView *)snapshotView;
-(void)obscurityViewRemovedForSnapshotView:(SBAppSwitcherSnapshotView *)snapshotView;

@end