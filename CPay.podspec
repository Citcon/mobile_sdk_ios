#
# Be sure to run `pod lib lint CPay.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'CPay'
  s.version          = '2.8.0'
  s.summary          = 'Online mobile SDK for iOS.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
    
  Release Citcon Online mobile SDK for iOS.
  
  The Citcon’s iOS app payment solution provides a convenient, safe, and reliable payment services to third-party applications. By using the SDK, merchant developers can focus on business logics without having to understand the pluming of payment transactions. The payment experience will be totally transparent and seamless to end consumers.
  
  
  DESC

  s.homepage         = 'https://github.com/Citcon/mobile_sdk_ios'
  s.license          = { :type => 'MIT' }
  s.author           = { 'yansheng.ao@citcon.cn' => 'yansheng.ao@citcon.cn' }
  s.source           = { :git => 'https://github.com/Citcon/mobile_sdk_ios.git', :tag => 'v' + s.version.to_s }


  s.pod_target_xcconfig = { 'BUILD_LIBRARY_FOR_DISTRIBUTION' => true }

# https://github.com/CocoaPods/CocoaPods/issues/10065#issuecomment-694266259
#  s.pod_target_xcconfig = { 'BUILD_LIBRARY_FOR_DISTRIBUTION' => true, 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.libraries = 'stdc++'#,'z','c++'
  s.requires_arc = true


  s.static_framework = false
  
  s.platform         = :ios, "13.0"
  # s.compiler_flags   = "-Wall -Werror -Wextra"
  # s.swift_version    = "5.1"
  # s.vendored_frameworks = 'CPay.xcframework'
  
  s.default_subspecs = ["Core", "Payment/CashApp/Core", "Payment/CashApp/Button"]

  s.subspec 'Core' do |ss|
    ss.vendored_frameworks = 'CPaySDK/Core/CPay.xcframework'
  end

  s.subspec 'Payment' do |ss|
    ss.subspec 'CashApp' do |sss|
      sss.subspec 'Core' do |ssss|
        ssss.vendored_frameworks = ['CPaySDK/Payment/CashApp/Ext/PayKit.xcframework']
      end
      
      sss.subspec 'Button' do |ssss|
        ssss.vendored_frameworks = ['CPaySDK/Payment/CashApp/Ext/PayKitUI.xcframework']
      end
    end
  end

end
