var
  a,b:array[0..12] of longint;
  s,i,k:longint;
  t:boolean;
procedure init;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to 12 do read(a[i]);
end;
procedure work;
begin
  s:=0;
  t:=true;
  for i:=1 to 12 do
    begin
      s:=s+300-a[i];
      if s<0 then
        begin
          t:=false;
          k:=i;
          break;
        end;
      b[i]:=s-s mod 100;
      b[i]:=trunc(b[i]*1.2);
      s:=s mod 100;
    end;
  for i:=1 to 12 do s:=s+b[i];
  if t then writeln(s)
       else writeln(-k);
end;
begin
  init;
  work;
end.