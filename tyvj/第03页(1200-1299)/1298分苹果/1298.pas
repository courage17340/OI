var
  a:int64;
  f:array[0..1000] of 0..1;
  n,k,i,j:longint;
begin
  readln(n,k);k:=k*2;
  a:=1;
  n:=n-1;
  i:=1001;
  while n>0 do
    begin
      dec(i);
      f[i]:=n mod 2;
      n:=n div 2;
    end;
  for j:=i to 1000 do
    begin
      a:=a*a mod k;
      if f[j]=1 then a:=a*3 mod k;
    end;
  a:=(a+1) div 2;
  writeln(a);
end.