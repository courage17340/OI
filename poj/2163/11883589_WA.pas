var
  a:array[0..10000] of extended;
  x,y:extended;
  n,m,i,j,k:longint;
  f:boolean;
begin
  f:=false;
  readln(m,n,k);
  for i:=1 to k do readln(a[i]);
  a[0]:=0;
  x:=0;
  for i:=n-m to n-1 do x:=x+a[i];
  y:=0;
  for i:=0 to n-1 do y:=y+a[i];
  for i:=n to k do
    begin
      x:=x+a[i]-a[i-m];
      y:=y+a[i]-a[i-n];
      if (x*n>y*m) xor f then
        begin
          if f then writeln('SELL ON DAY ',i) else writeln('BUY ON DAY ',i);
          f:=not f;
        end;
    end;
end.