import 'package:flutter/material.dart';

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  bool check = false;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Tennis Ball Shooting App"),
      ),
      body: Container(
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            children: [
              _emptySpace(),
              _btbuttons("BlueTooth Connect"),
              _emptySpace(),
              _buttons("Reset"),
              _emptySpace(),
              _buttons("Level1"),
              _emptySpace(),
              _buttons("Level2"),
              _emptySpace(),
              _buttons("Level3"),
            ],
          ),
        ),
      ),
    );
  }

  Widget _buttons(name) {
    return ElevatedButton(
        onPressed: _checked(check),
        child: Container(
          alignment: Alignment.center,
          width: 200,
          height: 50,
          child: Text(name,
              style: TextStyle(
                fontWeight: FontWeight.bold,
                fontSize: 16,
              )),
        ));
  }

  Widget _btbuttons(name) {
    return ElevatedButton(
        onPressed: () {
          setState(() {
            if (check == false) {
              _checked(true);
              check = true;
            } else {
              _checked(0);
              check = false;
            }
          });
        },
        child: Container(
            alignment: Alignment.center,
            width: 200,
            height: 50,
            child: Text(name,
                style: TextStyle(
                  fontWeight: FontWeight.bold,
                  fontSize: 16,
                  color: Colors.blue,
                ))));
  }

  Widget _emptySpace() {
    return Container(
      width: 100,
      height: 50,
    );
  }

  _checked(cnt) {
    if (cnt == true) {
      return () {};
    } else {
      return null;
    }
  }
}
