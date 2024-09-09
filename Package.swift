// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "CPay",
    platforms: [.iOS(.v13)],
    products: [
        .library(name: "CPay", targets: ["CPay"]),
        .library(name: "CashAppCore", targets: ["CashAppCore"]),
        .library(name: "CashAppButton", targets: ["CashAppButton", "CashAppCore"]),
    ],
    dependencies:[

    ],
    targets: [
        .binaryTarget(name: "CPay", path: "./CPaySDK/Core/CPay.xcframework"),
        .binaryTarget(name: "CashAppCore", path: "./CPaySDK/Payment/CashApp/Ext/PayKit.xcframework"),
        .binaryTarget(name: "CashAppButton", path: "./CPaySDK/Payment/CashApp/Ext/PayKitUI.xcframework"),
    ]
)
