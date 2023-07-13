//
//  LoadingView.m
//  CPayDemo
//
//  Created by long.zhao on 3/31/22.
//

#import "LoadingView.h"

#define UI_SCREEN_WIDTH     [UIScreen mainScreen].bounds.size.width
#define UI_SCREEN_HEIGHT    [UIScreen mainScreen].bounds.size.height

@interface LoadingView ()
@property (nonatomic, strong) UIActivityIndicatorView *aiv;
@end

@implementation LoadingView

+ (LoadingView *)sharedInst {
    static LoadingView *inst = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        inst = [LoadingView new];
    });
    return inst;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

- (instancetype)init {
    if (self = [super init]) {
        self.frame = CGRectMake(0, 0, UI_SCREEN_WIDTH, UI_SCREEN_HEIGHT);
        self.backgroundColor = [UIColor clearColor];
//        [[self topWindow] addSubview:self];
        [self addSubview:self.aiv];
    }
    return self;
}

- (UIActivityIndicatorView *)aiv {
    if (!_aiv) {
        _aiv = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
        _aiv.color = [UIColor blackColor];
        _aiv.center = self.center;
        _aiv.hidesWhenStopped = YES;
        
        CGAffineTransform transform = CGAffineTransformMakeScale(1.2, 1.2);
        _aiv.transform = transform;
    }
    return _aiv;
}

+ (void)show:(UIViewController *)vc {
    [[self sharedInst] showLoadingView:vc];
}

- (void)showLoadingView:(UIViewController *)vc {
    self.hidden = NO;
    [vc.view addSubview:self];
    [self.aiv startAnimating];
}

+ (void)dismiss {
    [[self sharedInst] dismissLoadingView];
}

- (void)dismissLoadingView {
    self.hidden = YES;
    [self.aiv stopAnimating];
    [self removeFromSuperview];
}

#pragma mark - utils

- (UIWindow *)topWindow {
    NSArray *wins = [UIApplication sharedApplication].windows;
    for (UIWindow *win in [wins reverseObjectEnumerator]) {
        if ([win isKindOfClass:[UIWindow class]] && CGRectEqualToRect(win.bounds, [UIScreen mainScreen].bounds)) {
            return win;
        }
    }
    return [UIApplication sharedApplication].keyWindow;
}

@end
