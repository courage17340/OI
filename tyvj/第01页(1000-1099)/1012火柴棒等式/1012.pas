var
  f:array[0..2000] of longint;
  n,ans,i,j:longint;
procedure work;
var
  i,j,x:longint;
begin
  fillchar(f,sizeof(f),0);
  for i:=0 to 2000 do
    begin
      x:=i;
      repeat
        j:=x mod 10;
        case j of
          0,6,9:f[i]:=f[i]+6;
          1:f[i]:=f[i]+2;
          2,3,5:f[i]:=f[i]+5;
          4:f[i]:=f[i]+4;
          7:f[i]:=f[i]+3;
          8:f[i]:=f[i]+7;
        end;
        x:=x div 10;
        until x=0;
    end;
end;
begin
  work;
  readln(n);
  ans:=0;
  for i:=0 to 1000 do
    for j:=0 to 1000 do
      if f[i]+f[j]+f[i+j]+4=n then inc(ans);
  writeln(ans);
end.