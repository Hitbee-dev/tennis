# tennis
* 한남대학교 기계공학과 캡스톤디자인 작품 테니스공 발사기 제어 어플


https://user-images.githubusercontent.com/83276163/150948658-66a43ab0-8ae0-42ee-a49d-db9534b0ef82.mp4




https://user-images.githubusercontent.com/83276163/150948682-16389f74-77db-4f9f-b9df-39cdaf02e4a1.mp4


## 한남대학교 공학페스티벌 금상
![공학페스티벌_원격 테니스공 자동발사기_금상](https://user-images.githubusercontent.com/83276163/150948966-188618f6-6234-4197-ae59-c2d12339b38a.png)


## 한남대학교 캡스톤디자인 경진대회 우수상
![캡스톤디자인 경진대회_원격 테니스공 자동발사기_우수상](https://user-images.githubusercontent.com/83276163/150949027-d287dca0-6860-40e3-b0ee-ca6f91b1563d.jpg)



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
