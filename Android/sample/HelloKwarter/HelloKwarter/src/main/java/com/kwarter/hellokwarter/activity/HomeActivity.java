package com.kwarter.hellokwarter.activity;

import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.widget.ListView;
import com.kwarter.hellokwarter.R;
import com.kwarter.hellokwarter.adapter.HomeListAdapter;

//
//  HomeActivity
//  HelloKwarter
//
//  Created by Elodie Ferrais
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

public class HomeActivity extends FragmentActivity {

    HomeListAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.listview);

        ListView listView = (ListView) findViewById(R.id.list);
        adapter = new HomeListAdapter(this);
        listView.setAdapter(adapter);
        listView.setOnItemClickListener(adapter);
    }
}
