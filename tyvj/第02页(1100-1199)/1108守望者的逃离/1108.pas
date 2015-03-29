var
  m,s,t,m1,s1,t1:longint;
  str:string;
procedure init;
begin
  readln(m,s,t);
end;
procedure work;
begin
  m1:=m;
  s1:=s;
  t1:=t;
  str:='';
  while m1>10 do
    begin
      m1:=m1-10;
      s1:=s1-60;
      t1:=t1-1;
      if s1<=0 then
        begin
          str:='Yes';
          break;
        end;
      if t1<=0 then
        begin
          str:='No';
          break;
        end;
    end;
  if str='' then
    begin
      if t1*17>=s1
        then
          str:='Yes'
        else
          begin
            while ((t1>=4) or (t1=3)and(m1+8>=10) or (t1=2)and(m1+4>=10))and(s1>0) do
              begin
                t1:=t1-1;
                m1:=m1+4;
                if m1>=10 then
                  begin
                    m1:=m1-10;
                    s1:=s1-60;
                    t1:=t1-1;
                  end;
              end;
            s1:=s1-t1*17;
            t1:=0;
            if s1>0 then
              str:='No'
              else
                str:='Yes';
          end;
    end;
end;
procedure escape;
begin
  if str='Yes'
    then
      begin
        m1:=m;
        s1:=s;
        t1:=t;
        while (m1>=10)and(s1>0) do
          begin
            t1:=t1-1;
            s1:=s1-60;
            m1:=m1-10;
          end;
        while s1>=69 do
          begin
            t1:=t1-1;
            m1:=m1+4;
            if m1>=10 then
              begin
                m1:=m1-10;
                s1:=s1-60;
                t1:=t1-1;
              end;
          end;
        if s1>0 then
          if s1<=17
            then t1:=t1-1
            else if s1<=34
              then t1:=t1-2
              else if s1<=51
                then if m1+4>=10
                  then t1:=t1-2
                  else t1:=t1-3
                else if m1+4>=10
                  then t1:=t1-3
                  else t1:=t1-4;
        writeln('Yes');
        write(t-t1);
      end;
  if str='No'
    then
      begin
        m1:=m;
        s1:=s;
        t1:=t;
        while (t1>0)and(m1>=10) do
          begin
            t1:=t1-1;
            s1:=s1-60;
            m1:=m1-10;
          end;
        while (t1>=4) or (t1=3)and(m1+8>=10) or (t1=2)and(m1+4>=10) do
          begin
            t1:=t1-1;
            m1:=m1+4;
            if m1>=10 then
              begin
                m1:=m1-10;
                s1:=s1-60;
                t1:=t1-1;
              end;
          end;
        s1:=s1-t1*17;
        writeln('No');
        write(s-s1);
      end;
  readln;
end;
begin{main}
  init;
  work;
  escape;
end.