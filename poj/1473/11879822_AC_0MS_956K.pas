var
  s,t:ansistring;
  i,p,k:longint;
  x,y:extended;
begin
  k:=0;
  while true do
    begin
      readln(s);
      if s='END' then break;
      inc(k);
      x:=0;
      y:=0;
      while length(s)>0 do
        begin
          if pos(',',s)>0 then
            begin
              t:=copy(s,1,pos(',',s)-1);
              delete(s,1,pos(',',s));
            end
            else
              begin
                delete(s,length(s),1);
                t:=s;
                s:='';
              end;
          p:=1;
          while t[p] in ['0'..'9'] do inc(p);
          val(copy(t,1,p-1),i);
          delete(t,1,p-1);
          if t='N' then y:=y+i;
          if t='S' then y:=y-i;
          if t='W' then x:=x-i;
          if t='E' then x:=x+i;
          if t='NW' then begin x:=x-i/sqrt(2);y:=y+i/sqrt(2);end;
          if t='NE' then begin x:=x+i/sqrt(2);y:=y+i/sqrt(2);end;
          if t='SW' then begin x:=x-i/sqrt(2);y:=y-i/sqrt(2);end;
          if t='SE' then begin x:=x+i/sqrt(2);y:=y-i/sqrt(2);end;
        end;
      if abs(x)<5e-4 then x:=0;
      if abs(y)<5e-4 then y:=0;
      writeln('Map #',k);
      writeln('The treasure is located at (',x:0:3,',',y:0:3,').');
      x:=sqrt(x*x+y*y);
      writeln('The distance to the treasure is ',x:0:3,'.');
      writeln;
    end;
end.