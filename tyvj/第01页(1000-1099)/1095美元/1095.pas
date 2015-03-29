var
  i,n,x:longint;
  f:array[0..101,0..1] of extended;
function max(a,b:extended):extended;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  readln(n);
  f[0,0]:=0;f[0,1]:=100;
  for i:=1 to n do
    begin
      readln(x);
      f[i,0]:=max(f[i-1,0],f[i-1,1]*(x/100));
      f[i,1]:=max(f[i-1,1],f[i-1,0]*(100/x));
    end;
  writeln(f[n,1]:0:2);
end.