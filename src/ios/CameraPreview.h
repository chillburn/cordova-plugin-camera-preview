#import <Cordova/CDV.h>
#import <Cordova/CDVPlugin.h>
#import <Cordova/CDVInvokedUrlCommand.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import "CameraSessionManager.h"
#import "CameraRenderController.h"

@interface CameraPreview : CDVPlugin <TakePictureDelegate, FocusDelegate, AVCaptureFileOutputRecordingDelegate>

- (void)startCamera:(CDVInvokedUrlCommand*)command;
- (void)stopCamera:(CDVInvokedUrlCommand*)command;
- (void)showCamera:(CDVInvokedUrlCommand*)command;
- (void)hideCamera:(CDVInvokedUrlCommand*)command;
- (void)getFocusMode:(CDVInvokedUrlCommand*)command;
- (void)setFocusMode:(CDVInvokedUrlCommand*)command;
- (void)getFlashMode:(CDVInvokedUrlCommand*)command;
- (void)setFlashMode:(CDVInvokedUrlCommand*)command;
- (void)setZoom:(CDVInvokedUrlCommand*)command;
- (void)getZoom:(CDVInvokedUrlCommand*)command;
- (void)getHorizontalFOV:(CDVInvokedUrlCommand*)command;
- (void)getMaxZoom:(CDVInvokedUrlCommand*)command;
- (void)getExposureModes:(CDVInvokedUrlCommand*)command;
- (void)getExposureMode:(CDVInvokedUrlCommand*)command;
- (void)setExposureMode:(CDVInvokedUrlCommand*)command;
- (void)getExposureCompensation:(CDVInvokedUrlCommand*)command;
- (void)setExposureCompensation:(CDVInvokedUrlCommand*)command;
- (void)getExposureCompensationRange:(CDVInvokedUrlCommand*)command;
- (void)setPreviewSize:(CDVInvokedUrlCommand*)command;
- (void)switchCamera:(CDVInvokedUrlCommand*)command;
- (void)takePicture:(CDVInvokedUrlCommand*)command;
- (void)takeSnapshot:(CDVInvokedUrlCommand*)command;
- (void)setColorEffect:(CDVInvokedUrlCommand*)command;
- (void)getSupportedPictureSizes:(CDVInvokedUrlCommand*)command;
- (void)getSupportedFlashModes:(CDVInvokedUrlCommand*)command;
- (void)getSupportedFocusModes:(CDVInvokedUrlCommand*)command;
- (void)tapToFocus:(CDVInvokedUrlCommand*)command;
- (void)getSupportedWhiteBalanceModes:(CDVInvokedUrlCommand*)command;
- (void)getWhiteBalanceMode:(CDVInvokedUrlCommand*)command;
- (void)setWhiteBalanceMode:(CDVInvokedUrlCommand*)command;

- (void)invokeTakePicture:(CGFloat)width withHeight:(CGFloat)height withQuality:(CGFloat)quality;
- (void)invokeTakePicture;
- (void)invokeTapToFocus:(CGPoint)point;

- (void)startRecordVideo:(CDVInvokedUrlCommand *)command;
- (void)onStartRecordVideo;
- (void)onStartRecordVideoError:(NSString *)message;
- (void)stopRecordVideo:(CDVInvokedUrlCommand *)command;
- (void)fileOutput:(AVCaptureFileOutput *)output didFinishRecordingToOutputFileAtURL:(NSURL *)outputFileURL fromConnections:(NSArray *)connections error:(NSError *)error;
- (void)onStopRecordVideo:(NSString *)filePath;
- (void)onStopRecordVideoError:(NSString *)errorMessage;
- (BOOL)hasView:(CDVInvokedUrlCommand *)command;
- (NSString *)getFilePath:(NSString *)filename;

@property (strong, nonatomic) CameraSessionManager *sessionManager;
@property (strong, nonatomic) CameraRenderController *cameraRenderController;
@property (nonatomic) NSString *onPictureTakenHandlerId;
@property (assign, nonatomic) BOOL storeToFile;
@property (strong, nonatomic) AVCaptureMovieFileOutput *movieFileOutput;
@property (strong, nonatomic) CDVInvokedUrlCommand *startRecordVideoCallbackContext;
@property (strong, nonatomic) CDVInvokedUrlCommand *stopRecordVideoCallbackContext;
@property (strong, nonatomic) NSString *videoFilePath;

@end
