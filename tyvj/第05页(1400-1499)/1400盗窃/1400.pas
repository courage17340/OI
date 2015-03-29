var
  a:array[0..100000] of longint;
  i,j,n,b,ans,x:longint;
begin
  readln(n,b);
  for i:=1 to n do read(a[i]);readln;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]*i=a[j]*j then
        begin
          x:=(i+j) div 2;
          break;
        end;
  ans:=0;
  case b of
    0:for i:=1 to x do ans:=ans+a[i];
    1:for i:=n downto x do ans:=ans+a[i];
    end;
  writeln(x,' ',ans);readln;
end.