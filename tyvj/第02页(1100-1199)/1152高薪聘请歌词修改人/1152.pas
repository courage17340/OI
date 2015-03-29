var
  mm,ss,tt,m,cs:longint;
  s,s1:ansistring;
  ch:char;
  p:extended;
begin
  read(ch);readln(p);
  m:=trunc(p);
  cs:=trunc(p*100)-m*100;
  repeat
    readln(s);
    if s<>'#' then
      if s[2] in ['0'..'9'] then
        begin
          s1:=copy(s,2,2);
          val(s1,mm);
          s1:=copy(s,5,2);
          val(s1,ss);
          s1:=copy(s,8,2);
          val(s1,tt);
          case ch of
            '-':begin
                  ss:=ss-m;tt:=tt-cs;
                  if tt<0 then begin tt:=tt+100;ss:=ss-1;end;
                  if ss<0 then begin ss:=ss+60;mm:=mm-1;end;
                end;
            '+':begin
                  ss:=ss+m;tt:=tt+cs;
                  if tt>99 then begin tt:=tt-100;ss:=ss+1;end;
                  if ss>59 then begin ss:=ss-60;mm:=mm+1;end;
                end;
            end;
          s[2]:=chr(mm div 10+48);s[3]:=chr(mm mod 10+48);
          s[5]:=chr(ss div 10+48);s[6]:=chr(ss mod 10+48);
          s[8]:=chr(tt div 10+48);s[9]:=chr(tt mod 10+48);
          writeln(s);
        end
         else writeln(s);
    until s='#';
end.