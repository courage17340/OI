var
  f:array[1..7] of longint;
  s,k:longint;
procedure init;
var
  a,b,i:longint;
begin
  fillchar(f,sizeof(f),0);
  for i:=1 to 7 do
    begin
      readln(a,b);
      f[i]:=a+b-8;
    end;
end;
procedure work;
var
  i:longint;
begin
  k:=0;
  s:=0;
  for i:=1 to 7 do
    if f[i]>0 then
      if s<f[i] then
        begin
          s:=f[i];
          k:=i;
        end;
  write(k);
end;
begin
  init;
  work;
end.