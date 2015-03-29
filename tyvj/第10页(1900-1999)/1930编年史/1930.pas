var
  a,b,c,yy,mm,dd,ww:longint;
  m:array[1..12] of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
  week:array[0..6] of string=('sunday','monday','tuesday','wednesday','thursday','friday','saturday');
function pan(yy:longint):boolean;
begin
  pan:=not((yy mod 4<>0)or(yy mod 100=0)and(yy mod 400<>0));
end;
function mon(x:longint):longint;
begin
  case x of
    2:if pan(yy) then exit(29) else exit(28);
    1,3..12:exit(m[x]);
  end;
end;
function f:longint;
var
  i,j:longint;
begin
  f:=0;
  f:=f+dd-1;dd:=1;
  while yy>a do
    begin
      if pan(yy) then inc(f);
      inc(f,365);
      dec(yy);
    end;
  while mm>b do
    begin
      dec(mm);
      inc(f,mon(mm));
    end;
  while mm<b do
    begin
      inc(mm);
      dec(f,mon(mm-1));
    end;
  dec(f,c-dd);
end;
begin
  readln(a,b,c);
  yy:=2012;mm:=8;dd:=28;ww:=2;
  ww:=ww-f;
  ww:=ww mod 7;
  if ww<0 then inc(ww,7);
  writeln(week[ww]);
  readln;
end.