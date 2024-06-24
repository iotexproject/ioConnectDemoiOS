//
//  ViewController.m
//  ioConnectDemoiOS
//
//  Created by Tang Timber on 2024/6/11.
//

#import "ViewController.h"
#include "DeviceConnect_Core.h"
#include "ioConnect.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"DeviceConnect_Core";
    // Do any additional setup after loading the view.
    UIButton *button = [[UIButton alloc] initWithFrame:CGRectMake(50, 50, 200, 50)];
    [button setBackgroundColor:UIColor.redColor];
    [button setTitle:@"call ioConnectMain" forState:UIControlStateNormal];
    [self.view addSubview:button];
    [button addTarget:self action:@selector(ioConnectMainButtonClick) forControlEvents:UIControlEventTouchUpInside];
    
}

- (void)ioConnectMainButtonClick {
    int status = [self ioConnectMain];
    NSLog([NSString stringWithFormat:@"status %d", status]);
}

- (int)ioConnectMain {
    iotex_io_connect_create_did();
    return 0;
}


@end
