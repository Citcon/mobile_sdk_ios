// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "CPaySDK",
    platforms: [.iOS(.v11)],
    products: [
        .library(name: "CPay.xcframework", targets: ["CPay"])
    ],
    targets: [
        .binaryTarget(name: "CPay", path: "./CPay.xcframework")
    ]
)

