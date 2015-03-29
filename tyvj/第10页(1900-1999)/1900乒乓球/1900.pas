var
  s:ansistring;
  ch:char;
  i,a,b:longint;
begin
  s:='';
  while true do
    begin
      read(ch);
      while not(ch in ['W','L','E']) do read(ch);
      if ch='E' then break;
      s:=s+ch;
    end;
  a:=0;b:=0;
  for i:=1 to length(s) do
    begin
      if s[i]='W' then inc(a) else inc(b);
      if (a=11)and(b<=9) or (b=11)and(a<=9) or (a-b>=2)and(b>=10) or (b-a>=2)and(a>=10) then
        begin
          writeln(a,':',b);
          a:=0;b:=0;
        end;
    end;
  writeln(a,':',b);
  writeln;
  a:=0;b:=0;
  for i:=1 to length(s) do
    begin
      if s[i]='W' then inc(a) else inc(b);
      if (a=21)and(b<=19) or (b=21)and(a<=19) or (a-b>=2)and(b>=20) or (b-a>=2)and(a>=20) then
        begin
          writeln(a,':',b);
          a:=0;b:=0;
        end;
    end;
  writeln(a,':',b);
end.