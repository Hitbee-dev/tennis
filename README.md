# tennis
* 한남대학교 기계공학과 캡스톤디자인 작품 테니스공 발사기 제어 어플

### Arduino
* 데이터 받는 부분

``` C
temp = Serial1.read();
```

### Flutter
* 데이터 보내는 부분

``` Dart
class DeviceScreen extends StatelessWidget {
  const DeviceScreen({Key? key, required this.device}) : super(key: key);
  final BluetoothDevice device;

  List<Widget> _buildServiceTiles(List<BluetoothService> services) {
    return services
        .map(
          (s) => ServiceTile(
            service: s,
            characteristicTiles: s.characteristics
                .map(
                  (c) => CharacteristicTile(
                    characteristic: c,
                    onReadPressed: () => c.read(),
                    onWriteReset: () async {
                      //101=e, 102=f, 103=g, 104=h
                      await c.write([101], withoutResponse: true);
                      await c.read();
                    },
                    onWriteLevel1: () async {
                      //101=e, 102=f, 103=g, 104=h
                      await c.write([102], withoutResponse: true);
                      await c.read();
                    },
                    onWriteLevel2: () async {
                      //101=e, 102=f, 103=g, 104=h
                      await c.write([103], withoutResponse: true);
                      await c.read();
                    },
                    onWriteLevel3: () async {
                      //101=e, 102=f, 103=g, 104=h
                      await c.write([104], withoutResponse: true);
                      await c.read();
                    },
                  ),
                )
                .toList(),
          ),
        )
        .toList();
  }
```
# Data add nesessary
