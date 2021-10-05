import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:tennis/page/bluetooth.dart';

void main() {
  runApp(Tennis());
}

class Tennis extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return GetMaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Tennis Ball Shooting App',
      theme: ThemeData(
        primarySwatch: Colors.amber,
      ),
      initialRoute: "/",
      getPages: [
        GetPage(
            name: "/",
            page: () => Bluetooth(),
            transition: Transition.cupertinoDialog),
      ],
    );
  }
}
