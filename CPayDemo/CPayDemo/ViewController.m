//
//  ViewController.m
//  CPayDemo
//
//  Created by long.zhao on 3/28/22.
//

#import "ViewController.h"
#import "LoadingView.h"
#import "AppInstance.h"
#import <CPay/CPay.h>
#import "TokenHeader.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextField *txtRef;
@property (weak, nonatomic) IBOutlet UITextField *txtCurrency;
@property (weak, nonatomic) IBOutlet UITextField *txtCountry;
@property (weak, nonatomic) IBOutlet UITextField *txtAmount;
@property (weak, nonatomic) IBOutlet UISwitch *swDuplicate;
@property (weak, nonatomic) IBOutlet UITextField *txtVendor;
@property (weak, nonatomic) IBOutlet UISwitch *swAcceleration;
@property (weak, nonatomic) IBOutlet UITextField *txtSubject;
@property (weak, nonatomic) IBOutlet UITextField *txtBody;
@property (weak, nonatomic) IBOutlet UITextField *txtIPN;
@property (weak, nonatomic) IBOutlet UITextField *txtCallbackUrl;
@property (weak, nonatomic) IBOutlet UITextField *txtFailUrl;
@property (weak, nonatomic) IBOutlet UITextField *txtCancelUrl;
@property (weak, nonatomic) IBOutlet UITextField *txtScheme;
@property (weak, nonatomic) IBOutlet UITextField *txtUniversalLink;
@property (weak, nonatomic) IBOutlet UITextField *txtFirstName;
@property (weak, nonatomic) IBOutlet UITextField *txtLastName;
@property (weak, nonatomic) IBOutlet UITextField *txtPhone;
@property (weak, nonatomic) IBOutlet UITextField *txtEmail;
@property (weak, nonatomic) IBOutlet UITextField *txtTaxableAmount;
@property (weak, nonatomic) IBOutlet UITextField *txtTaxExemptAmount;
@property (weak, nonatomic) IBOutlet UITextField *txtTotalTaxAmount;
@property (weak, nonatomic) IBOutlet UITextField *txtConsumerRef;
@property (weak, nonatomic) IBOutlet UITextField *txtToken;
@property (weak, nonatomic) IBOutlet UILabel *lblSyncResult;
@property (weak, nonatomic) IBOutlet UILabel *lblAsyncResult;
@property (weak, nonatomic) IBOutlet UISwitch *swQueryByRef;
@property (weak, nonatomic) IBOutlet UILabel *lblVersionNo;
@property (weak, nonatomic) IBOutlet UITextField *txtEnv;
@property (weak, nonatomic) IBOutlet UITextField *txtExtraKey;
@property (weak, nonatomic) IBOutlet UITextField *txtExtraValue;
@property (weak, nonatomic) IBOutlet UITextField *txtInstallments;
@property (weak, nonatomic) IBOutlet UISwitch *swInstallments;

@property (strong, nonatomic) UIPickerView *picker;
@property (strong, nonatomic) UITextField *currentTextField;
@property (strong, nonatomic) NSArray *pickerData;

@property (strong, nonatomic) NSString *transId;
@property (weak, nonatomic) IBOutlet UITextField *sourceField;
@property (weak, nonatomic) IBOutlet UITextField *noteField;
@property (weak, nonatomic) IBOutlet UISwitch *autoCaptureSwitcher;
@property (weak, nonatomic) IBOutlet UIButton *chargeBtn;

@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self initUI];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onResp:) name:kOrderPaymentFinishedNotification object:nil];
    
    NSLog(@"SDK Version: %@", [CPayManager getVersion]);

    NSLog(@"yunshanfu install: %d",[CPayManager isUnionPayInstalled]);
}

- (void)initUI {
    _lblVersionNo.text = [NSString stringWithFormat:@"Version %@", [CPayManager getVersion]];
    
    [self initUIPicker];
    [self initTouch];
    [self initOrderForm];
    [self addGesture:@selector(currencyGesture) txtField:_txtCurrency];
    [self addGesture:@selector(vendorGesture) txtField:_txtVendor];
    [self addGesture:@selector(countryGesture) txtField:_txtCountry];
    [self addGesture:@selector(envGesture) txtField:_txtEnv];
    
    [self cashAppButton];
    
    
    
}

- (void)initOrderForm {
    _swAcceleration.on = NO;
    _swQueryByRef.on = NO;
    _swInstallments.on = NO;
    _autoCaptureSwitcher.on = TRUE;
    
    [self generateRef];
//    _txtCurrency.text = @"KRW";
    _txtCurrency.text = @"USD";
    _txtCountry.text = @"US";
//    _txtAmount.text = @"100";
    _txtAmount.text = @"1";
//    _txtVendor.text = @"card";
    _txtVendor.text = @"alipay";
    _txtVendor.text = @"cashapppay";

//    _txtSubject.text = @"subject";
//    _txtBody.text = @"body";
    _txtIPN.text = @"https://ipn-receive.qa01.citconpay.com/notify";
    
    _txtCallbackUrl.text = @"com.citcon.citconpay://";
    _txtCancelUrl.text = @"com.citcon.citconpay://";
    _txtFailUrl.text = @"com.citcon.citconpay://";
    
//    _txtCallbackUrl.text = @"https://success";
//    _txtCancelUrl.text = @"https://cancel";
//    _txtFailUrl.text = @"https://fail";
//    
    
    
    _txtScheme.text = @"com.citcon.citconpay";
    
    _txtUniversalLink.text = @"https://dev.citconpay.com/cpaydemo";
    _txtFirstName.text = @"Liu";
    _txtLastName.text = @"Diao";
    _txtPhone.text = @"18899000091";
    _txtEmail.text = @"liu.diao@citcon.cn";
//    _txtConsumerRef.text = @"consumer-reference-000";
//    _txtTaxableAmount.text = @"0";
//    _txtTaxExemptAmount.text = @"0";
//    _txtTotalTaxAmount.text = @"0";
//    _txtExtraKey.text = @"extra key";
//    _txtExtraValue.text = @"extra value";

    _sourceField.text = @"app_h5";
    
    _txtToken.text = SDK_TOKEN;
    
    _txtEnv.text = @"UAT";
    

}

- (void)initTouch {
    UITapGestureRecognizer *bgTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(onBgTap:)];
    [self.view addGestureRecognizer:bgTap];
}

- (void)initUIPicker {
    _picker = [[UIPickerView alloc] initWithFrame:CGRectMake(0, self.view.frame.size.height, self.view.frame.size.width, self.view.frame.size.height/3)];
    [_picker setBackgroundColor:[UIColor systemGrayColor]];
    [_picker setDataSource:self];
    [_picker setDelegate:self];
    [self.view addSubview:_picker];
}

- (void)addGesture:(SEL)sel txtField:(id)txtField {
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:sel];
    [txtField addGestureRecognizer:tap];
}

- (void)generateRef {
    _txtRef.text = [NSString stringWithFormat:@"sdk_demo_%ld", (long)([[NSDate date] timeIntervalSince1970] * 1000000)];
}

- (void)setEnv {
    NSString *token = _txtToken.text;
    if (token == nil || token.length < 1) {
        return;
    }
//    [self generateRef];
    
    [CPayManager setupTokenKey:token];
    [CPayManager setupMode:[AppInstance modeby:_txtEnv.text]];
}

- (CPayOrder *)createOrder {
    CPayOrder *order = [CPayOrder new];
    order.currency = _txtCurrency.text;
    order.vendor = _txtVendor.text;
    order.callbackUrl = _txtCallbackUrl.text;
    order.amount = _txtAmount.text;
    order.ipnUrl = _txtIPN.text;
    order.scheme = _txtScheme.text;
    order.universalLink = _txtUniversalLink.text;
    order.cancelUrl = _txtCancelUrl.text;
    order.callbackFail = _txtFailUrl.text;
    order.subject = _txtSubject.text;
    order.body = _txtBody.text;
    order.allowDuplicate = _swDuplicate.isOn;
    order.country = _txtCountry.text;
    
    
    if (![_txtVendor.text isEqualToString:@"cashapppay"]) {
        order.phone = _txtPhone.text;
        order.firstName = _txtFirstName.text;
        order.lastName = _txtLastName.text;
        order.email = _txtEmail.text;
        order.consumerReference = _txtConsumerRef.text;
        order.taxableAmount = _txtTaxableAmount.text;
        order.taxExemptAmount = _txtTaxExemptAmount.text;
        order.totalTaxAmount = _txtTotalTaxAmount.text;
    }
    
    
    order.isAccelerateCNPay = _swAcceleration.isOn;
    order.controller = self;
    order.unionPayMode = CPayUnionDevMode;
    order.referenceId = _txtRef.text;
    
    order.source = _sourceField.text;
    order.note = _noteField.text;
    order.autoCapture = _autoCaptureSwitcher.isOn;
    
    if (_swInstallments.isOn) {
        order.installmentId = _txtInstallments.text;
    }
    
//    order.cashReceiptType = @"income_deduction";
    
    return order;
}

#pragma mark - Utils

- (void)showPicker {
    self.picker.alpha = 1;
    [UIView animateWithDuration:0.3 animations:^{
        self.picker.frame = CGRectMake(0, self.view.frame.size.height*.67, self.view.frame.size.width, self.view.frame.size.height/3);
    } completion:^(BOOL finished) {
        [self.picker reloadAllComponents];
    }];
}

- (void)dismissPicker {
    [UIView animateWithDuration:0.3 animations:^{
        self.picker.frame = CGRectMake(0, self.view.frame.size.height, self.view.frame.size.width, self.view.frame.size.height/3);
    } completion:^(BOOL finished) {
        self.picker.alpha = 0;
    }];
}

- (void)showAlert:(NSString *)title message:(NSString *)message {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *act = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [alert addAction:act];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)showOrderResult:(CPayOrderResult *)result {
    NSMutableString *str = [NSMutableString new];
    [str appendFormat:@"    status: %ld\n", (long)result.resultStatus];
    [str appendFormat:@"    message: %@\n", result.message];
    [str appendFormat:@"    result: %@\n", result.result];
    [str appendFormat:@"    vendor: %@\n", result.order.vendor];
    [str appendFormat:@"    txn id: %@\n", result.order.transactionId];
    [str appendFormat:@"    ref id: %@\n", result.order.referenceId];
    [str appendFormat:@"    currency: %@ \n    amount: %@\n", result.order.currency, result.order.amount];
    
    
    [self updateResult:self.lblSyncResult text:[NSString stringWithFormat:@"%@", str]];
    
}

- (CGFloat)getLabelHeight:(UILabel *)label {
    NSMutableParagraphStyle *style = [[NSMutableParagraphStyle alloc] init];
    [style setLineBreakMode:label.lineBreakMode];
    [style setAlignment:NSTextAlignmentLeft];
    NSDictionary *dic = @{NSFontAttributeName :label.font, NSParagraphStyleAttributeName : style};
    CGSize size = [label.text boundingRectWithSize:CGSizeMake(label.frame.size.width, MAXFLOAT) options:(NSStringDrawingUsesLineFragmentOrigin) attributes:dic context:nil].size;
    return size.height;
}

- (void)showCheckResult:(CPayCheckResult *)result {
    NSMutableString *str = [NSMutableString new];
    [str appendFormat:@"\n    status: %@\n", result.status];
    [str appendFormat:@"    type: %@\n", result.type];
    [str appendFormat:@"    txn id: %@\n", result.transactionId];
    [str appendFormat:@"    ref id: %@\n", result.referenceId];
    [str appendFormat:@"    currency: %@ \n    amount: %@\n", result.currency, result.amount];
    [str appendFormat:@"    refunded amount: %@ \n    time: %@", result.refunded_amount, result.time];
    
    [self updateResult:self.lblAsyncResult text:[NSString stringWithFormat:@"%@", str]];

}

- (void)resetResult {
    self.lblSyncResult.text = nil;
    self.lblAsyncResult.text = nil;
}

- (void)showResult:(id)result {
    if ([result isKindOfClass:[CPayOrderResult class]]) {
        [self showOrderResult:result];
    } else if ([result isKindOfClass:[CPayCheckResult class]]) {
        [self showCheckResult:result];
    }
}

- (void)resetTransId {
    _transId = nil;
}

#pragma mark - UIPicker delegate & data source

- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component {
    return 30;
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    NSString *_d = self.pickerData[row];
    if (_d) self.currentTextField.text = _d;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    return self.pickerData.count;
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    return self.pickerData[row];
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

#pragma mark - Delegate

- (void)currencyGesture {
    self.currentTextField = _txtCurrency;
    self.pickerData = [AppInstance currencies];
    [self showPicker];
}

- (void)countryGesture {
    self.currentTextField = _txtCountry;
    self.pickerData = [AppInstance countries];
    [self showPicker];
}

- (void)vendorGesture {
    self.currentTextField = _txtVendor;
    self.pickerData = [AppInstance vendors];
    [self showPicker];
}

- (void)envGesture {
    self.currentTextField = _txtEnv;
    self.pickerData = [AppInstance envs];
    [self showPicker];
}

- (void)onBgTap:(UITapGestureRecognizer *)gesture {
    [self.view endEditing:YES];
    [self dismissPicker];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}

- (IBAction)onCharge:(id)sender {
    [self generateRef];

    
    [LoadingView show:self];
    [self setEnv];
    [self resetResult];
    [CPayManager requestOrder:[self createOrder] completion:^(CPayOrderResult *result) {
        [LoadingView dismiss];
        NSLog(@"on callback: code(%@) result:(%@) message:(%@)", @(result.resultStatus), result.result, result.message);
        self.transId = [result.order.transactionId mutableCopy];
        [self showResult:result];
    }];
}

- (IBAction)onQuery:(id)sender {
    BOOL byRef = _swQueryByRef.isOn;
    if (byRef) {
        NSString *refId = _txtRef.text;
        if (refId == nil || refId.length < 1) {
            return [self showAlert:@"Error" message:@"Reference can not be empty"];
        }
        
        [LoadingView show:self];
        [self setEnv];
        [CPayManager inquireResultByRef:refId order:[self createOrder] method:@"real" completion:^(CPayCheckResult *result) {
            [LoadingView dismiss];
            NSLog(@"on query: status(%@)", result.status);
            [self showResult:result];
        }];
    } else {
        if (_transId == nil || _transId.length < 1) {
            return [self showAlert:@"Error" message:@"Transaction Id can not be empty"];
        }
        [LoadingView show:self];
        [self setEnv];
        [CPayManager inquireResult:_transId order:[self createOrder] method:@"real" completion:^(CPayCheckResult *result) {
            [LoadingView dismiss];
            NSLog(@"on query: status(%@)", result.status);
            [self showResult:result];
        }];
    }
}

- (void)onResp:(NSNotification *)notification {
    [LoadingView dismiss];
    CPayCheckResult *result = notification.object;
    NSLog(@"on notify: status(%@)", result.status);
    [self showResult:result];
}

- (void)updateResult:(UILabel *)label text:(NSString *)text {
    label.text = text;
    return;
    
    CGFloat height = [self getLabelHeight:label];
    //    label.translatesAutoresizingMaskIntoConstraints = true;
    //    label.frame = CGRectMake(label.frame.origin.x, label.frame.origin.y, label.frame.size.width, height);

//    [label.heightAnchor constraintEqualToConstant:height].active = YES;
//    [label setNeedsLayout];
//    [label layoutIfNeeded];
    
    for (NSLayoutConstraint *constraint in label.constraints) {
        if (constraint.firstAttribute == NSLayoutAttributeHeight) {
            // remove auto generated layout height constraint
            if ([constraint isKindOfClass:NSClassFromString(@"NSContentSizeLayoutConstraint")]) {
                [label removeConstraint:constraint];
                continue;
            }
            
            // update label height
            constraint.constant = height;
        }
    }
    
//    NSLog(@"All Constraints: %@", label.constraints);
    
    
    [self.view layoutIfNeeded];


}


- (void)cashAppButton {
        {
            UIView *button =
            [CPayStyleManager buildCashAppPaymentButtonWithSize:@"large" action:^{
                [self buttonTapped];
            }];
            
            if (button) {
                [self.scrollView addSubview:button];
                
                [NSLayoutConstraint activateConstraints:@[
                    [button.bottomAnchor constraintEqualToAnchor:self.chargeBtn.bottomAnchor constant:10 + 70],
                    [button.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor]
                ]];
            }
            
        }
        
        {
            UIView *button =
            [CPayStyleManager buildCashAppPaymentMethodWithSize:@"large" cashTag:@"$USD" cashTagColor:[UIColor redColor] cashTagFont: [UIFont systemFontOfSize:10]];
            
            if (button) {
                [self.scrollView addSubview:button];
                
                [NSLayoutConstraint activateConstraints:@[
                    [button.bottomAnchor constraintEqualToAnchor:self.chargeBtn.bottomAnchor constant:10 + 110],
                    [button.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor]
                ]];
                
            }
        }
        
}


- (void)buttonTapped {
    [self onCharge:nil];
}


@end
