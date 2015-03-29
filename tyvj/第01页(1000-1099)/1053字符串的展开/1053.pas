var
  s:ansistring;
  p1,p2,p3,i,j:longint;
function ni(s:ansistring):ansistring;
var
  ss:ansistring;
  i:longint;
begin
  ss:='';
  for i:=length(s) downto 1 do ss:=ss+s[i];
  exit(ss);
end;
function zhuan(x:char):char;
begin
  case p1 of
    1:exit(x);
    2:exit(upcase(x));
    3:exit('*');
  end;
end;
function ff(a,b:char):ansistring;
var
  i:longint;
  ch:char;
begin
  a:=chr(ord(a)+1);b:=chr(ord(b)-1);
  ff:='';
  for ch:=a to b do for i:=1 to p2 do ff:=ff+zhuan(ch);
  if p3=2 then ff:=ni(ff);
end;
function yes1(a,b:longint):boolean;
begin
  if (a=0)or(b=length(s)+1) then exit(false);
  yes1:=false;
  if (s[a] in ['a'..'z'])and(s[b] in ['a'..'z']) then exit(true);
  if (s[a] in ['0'..'9'])and(s[b] in ['0'..'9']) then exit(true);
end;
function yes2(a,b:longint):boolean;
begin
  if (a=0)or(b=length(s)+1) then exit(false);
  yes2:=false;
  if ord(s[b])-ord(s[a])>1 then exit(true);
end;
begin
  readln(p1,p2,p3);
  readln(s);
  for i:=1 to length(s) do
    if s[i]<>'-'
      then write(s[i])
      else
        begin
          if yes1(i-1,i+1)and yes2(i-1,i+1) then begin write(ff(s[i-1],s[i+1]));continue;end;
          if yes1(i-1,i+1)and (s[i+1]=succ(s[i-1])) then continue;
          write('-');
        end;
  writeln;
end.
