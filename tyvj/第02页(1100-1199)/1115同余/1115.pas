var
  n,i,j,x,max:longint;
  a:array[1..100] of longint;
  t:boolean;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to 1000000 do
    begin
      x:=a[1] mod i;
      t:=true;
      for j:=2 to n do
        if a[j] mod i<>x then
          begin
            t:=false;
            break;
          end;
      if t then max:=i;
    end;
  writeln(max);
end.