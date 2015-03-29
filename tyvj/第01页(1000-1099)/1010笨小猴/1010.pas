var
  a:array['a'..'z'] of longint;
  max,min:longint;
  ch:char;
procedure init;
begin
  fillchar(a,sizeof(a),0);
  while not eoln do
    begin
      read(ch);
      inc(a[ch]);
    end;
end;
function zhi(x:longint):boolean;
var
  i:longint;
begin
  if x<2 then exit(false);
  zhi:=true;
  for i:=2 to trunc(sqrt(x)) do
    if x mod i=0 then exit(false);
end;
procedure work;
var
  i:longint;
begin
  max:=0;
  min:=maxlongint;
  for ch:='a' to 'z' do
    begin
      if max<a[ch] then max:=a[ch];
      if a[ch]>0 then if min>a[ch] then min:=a[ch];
    end;
  if zhi(max-min) then
    begin
      writeln('Lucky Word');
      writeln(max-min);
    end
    else
      begin
        writeln('No Answer');
        writeln(0);
      end;
end;
begin
  init;
  work;
end.