# IP Converter

### Функции

Конвертация IP из строки в число: 
```pawn
IP::int_to_string(ip);
```

Конвертация IP из числа в строку:
```pawn
IP::string_to_int(const ip[]);
```

### Примеры

```pawn
new ip = IP::string_to_int("176.120.211.212");
```

```pawn
new ip[16];
strcat(ip, IP::int_to_string(-1334258732));
```	
