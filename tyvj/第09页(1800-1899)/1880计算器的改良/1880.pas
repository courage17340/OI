var
  ch:char;
  i,p,k,k1:longint;{k——判断等号;k1——符号}
  xx:array[1..2] of longint;{1-数值;2-1/未知数,2/数字}
  a,b:longint;
  s:string;
function min(a,b:longint):longint;
begin
  if a=0 then exit(b);
  min:=a;if (a>b)and(b>0) then min:=b;
end;
begin
  readln(s);
  k:=1;
  for i:=1 to length(s) do
    if not (s[i] in ['0'..'9','+','-','=']) then begin ch:=s[i];break;end;
  a:=0;
  b:=0;
  while s<>'' do
    begin
      {writeln(s);readln;}
      k1:=1;
      if s[1]='=' then begin k:=-1;delete(s,1,1);end;
      p:=min(pos('-',s),pos('+',s));
      if p=1 then begin k1:=-1;delete(s,1,1);end;
      p:=min(pos('-',s),pos('+',s));
      p:=min(p,pos('=',s));
      if p=0 then if pos('=',s)>0 then p:=pos('=',s) else p:=length(s)+1;
      if p=2 then
        if s[1]=ch then begin xx[1]:=k1;xx[2]:=1;end
                   else begin val(s[1],xx[1],i);xx[1]:=xx[1]*k1;xx[2]:=2;end
        else
          if s[p-1]=ch then
            begin
              val(copy(s,1,p-2),xx[1],i);
              xx[1]:=xx[1]*k1;xx[2]:=1;
            end
          else
            begin
              val(copy(s,1,p-1),xx[1],i);
              xx[1]:=xx[1]*k1;xx[2]:=2;
            end;
      delete(s,1,p-1);
      if s[1]='+' then delete(s,1,1);
      if xx[2]=1 then inc(a,xx[1]*k) else dec(b,xx[1]*k);
    end;
  if b=0 then writeln(ch,'=','0.000')else writeln(ch,'=',b/a:0:3);
end.