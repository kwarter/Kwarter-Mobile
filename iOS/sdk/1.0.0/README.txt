Steps to install:

1. Drag and drop the KwarterSDK.framework in the framework section
2. Drag and drop the 3 bundles and the momd file from the KwarterSDK.framework to your project. They are inside the framework folder:
	- KwarterSDK.bundle
	- DefaultEnvironments.bundle
	- SSToolkitResources.bundle
	- KwarterModel.momd
3. Add the #import <KwarterSDK/KwarterSDK.h> inside the <APPLICATION_NAME>-Prefix.pch in the ifdef section
4. Import the required frameworks:
	- CoreData
	- MessageUI
	- MobileCoreServices
	- QuartzCore
	- Security
	- SystemConfiguration
5. In the application:didFinishLaunchingWithOptions: start the SDK with your client id
	[Kwarter startWithClientId:<YOUR_CLIENT_ID> secret:<YOUR_SECRET>];