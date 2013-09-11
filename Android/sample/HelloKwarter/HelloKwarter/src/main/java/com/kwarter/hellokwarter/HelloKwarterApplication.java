package com.kwarter.hellokwarter;

import android.app.Application;

import com.kwarter.android.sdk.Kwarter;

//
//  HelloKwarterApplication
//  HelloKwarter
//
//  Created by Elodie Ferrais
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

public class HelloKwarterApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();

        // Start Kwarter SDK
        Kwarter.startWithClientIdAndSecret(this,"Dcfpc0R2QNkpdywe", null );

        // Environments provided by the SDK are Environment.BETA and Environment.LIVE
        Kwarter.getSharedInstance().setCurrentEnvironment(Kwarter.Environment.BETA);
    }
}
